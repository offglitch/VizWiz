// Fill out your copyright notice in the Description page of Project Settings.

#include "SpectralPlayer.h"

// Sets default values
ASpectralPlayer::ASpectralPlayer()
	: CurrentClipIndex(-1)
	, SpectrumBarNum(100)
	, LinearInterpWeight(0.1f)
	, SpectrumFequencyLimits(20, 20000)
	, FFTSize(ETimeSynthFFTSize::Large_1024)
	, PlayerState(EPlayerState::Stopped)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Pointer to instance of class
	PlayerInstance = this;

	//Creating the timesynth component
	TimeSynthComponent = CreateDefaultSubobject<UTimeSynthComponent>("TimeSnythComponent");

	//set Envelope Follower default settings
	TimeSynthComponent->SetEnvelopeFollowerEnabled(true);
	TimeSynthComponent->SetEnvelopeFollowerSettings(FTimeSynthEnvelopeFollowerSettings());

	//Enabling spectral analysis allows the bars to "do something"
	TimeSynthComponent->bEnableSpectralAnalysis = true;

	//Root of the actor, all spectrum bars will attach to
	SetRootComponent(TimeSynthComponent);

	//Delegate instead of Tick
	TimeSynthComponent->OnPlaybackTime.AddUniqueDynamic(this, &ASpectralPlayer::PlayerPlayback);
}

// Called when the game starts or when spawned
void ASpectralPlayer::BeginPlay()
{
	Super::BeginPlay();
	/*Init*/
	LerpSpectralData.Init(0.f, SpectrumBarNum);
	MaxSpectralData.Init(KINDA_SMALL_NUMBER, SpectrumBarNum); //Avoid division by zero

	//right now TimeSynthComponent gets triggered on runtime
	//TODO: trigger on collision for further prototyping
	//Play(CurrentClipIndex);
}

void ASpectralPlayer::PlayerPlayback(float SynthPlaybackTimeSeconds)
{
	//Getting Spectral Data and Envelope Follower
	const auto& spectralData = TimeSynthComponent->GetSpectralData();
	const auto envelope      = TimeSynthComponent->GetEnvelopeFollowerValue();
	// iterate over the spectral data
	// SpecData is just struct with frequency and the amplitude of that frequency
	if (spectralData.Num())
	{
		for (int32 i = 0; i < SpectrumBarNum; ++i)
		{
			const float curMagnitude = spectralData[i].Magnitude;         // magnitute for current bar
			float& maxMagnitude      = MaxSpectralData[i];                // max magnitude from history
			if (maxMagnitude < curMagnitude) maxMagnitude = curMagnitude; // update max if needed
			float& lerpMagnitude = LerpSpectralData[i];                   // interpolated magnitude from history
			// peak normalization
			lerpMagnitude = FMath::LerpStable(lerpMagnitude, curMagnitude / maxMagnitude, LinearInterpWeight);
			// quieter sound slower decrease last peak (not sure)
			maxMagnitude = FMath::FInterpTo(maxMagnitude, KINDA_SMALL_NUMBER, GetWorld()->GetDeltaSeconds(), envelope);
		}
		// broadcast for listeners
		OnSpectrumUpdate.Broadcast(LerpSpectralData);
	}
}


void ASpectralPlayer::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	//Clear Frequencies To Analyze array
	TimeSynthComponent->FrequenciesToAnalyze.Empty();

	const float freqMin   = FMath::Min(FMath::Abs(SpectrumFequencyLimits.Y), FMath::Abs(SpectrumFequencyLimits.X));
	const float freqRange = FMath::Abs(FMath::Abs(SpectrumFequencyLimits.Y) - FMath::Abs(SpectrumFequencyLimits.X));
	const float freqStep  = freqRange / (SpectrumBarNum - 1);
	//Adding Frequencies To Analyze array
	for (int32 i = 0; i < SpectrumBarNum; ++i)
	{
		TimeSynthComponent->FrequenciesToAnalyze.Add(freqMin + i * freqStep);
	}
	//Set FFT size
	TimeSynthComponent->FFTSize = FFTSize;
}

void ASpectralPlayer::Play(int32 ClipIndex)
{
	if (ClipIndex < TimeSynthClips.Num())
	{
		CurrentClipIndex = ClipIndex;
		// stop if playing
		if (PlayerState == EPlayerState::Playing)
			TimeSynthComponent->StopClip(ClipHandle, ETimeSynthEventClipQuantization::Global);
		// play with saving clip handle
		ClipHandle = TimeSynthComponent->PlayClip(TimeSynthClips[CurrentClipIndex]);
		//setting PlayerStart(FTimeSynthClipHandle has only operator==)
		PlayerState = (ClipHandle == FTimeSynthClipHandle() ? EPlayerState::Stopped : EPlayerState::Playing);
	}
}

void ASpectralPlayer::Stop()
{
	if (PlayerState == EPlayerState::Playing)
	{
		TimeSynthComponent->StopClip(ClipHandle, ETimeSynthEventClipQuantization::Global);
		PlayerState = EPlayerState::Stopped;
	}
}