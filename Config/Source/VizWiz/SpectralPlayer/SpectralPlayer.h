// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimeSynthComponent.h"
#include "GameFramework/Actor.h"
#include "SpectralPlayer.generated.h"


UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	Playing,
	Stopped
};

// Make abstract and minimalapi for using only children, uncomment VIZWIZ_API if remove MinimalAPI spec
// Hide component settings from main BP (still available through component branch
UCLASS(Abstract, MinimalAPI, HideCategories=(TimeSynthComponent))
class /*VIZWIZ_API*/ ASpectralPlayer : public AActor
{
	GENERATED_BODY()

public:
	//Delegates for player construction and spectrum update
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerConstruction);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpectrumUpdate, const TArray<float>&, SpectralData);

	UPROPERTY(BlueprintAssignable)
	FOnPlayerConstruction OnPlayerConstruction;
	UPROPERTY(BlueprintAssignable)
	FOnSpectrumUpdate OnSpectrumUpdate;

	//Ptr for instance. C++17 allows init static ptr with inline spec
	static inline ASpectralPlayer* PlayerInstance = nullptr;

public:	
	// Sets default values for this actor's properties
	ASpectralPlayer();

	// Called at the end of ExecuteConstruction, which calls the blueprint construction script.
	virtual void OnConstruction(const FTransform& Transform) override;

	//Player control
	void Play(int32 ClipIndex);
	UFUNCTION()  //need UFUNCTION for dynamic delegate
	void Stop();

	//Getters
	int32 GetSpectrumBarNum() const	{ return SpectrumBarNum; }
	const TArray<UTimeSynthClip*>& GetTimeSynthClips() const { return TimeSynthClips; }
	int32 GetCurrentClipIndex() const { return CurrentClipIndex; }

protected:
	//This is the core of the actor, the TimeSynth component
	//hidden
	UPROPERTY(VisibleAnywhere, Category = "TimeSynthComponent", BlueprintReadOnly)
	UTimeSynthComponent* TimeSynthComponent;

	//TSClip represents that piece of audio from TSComponent 
	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	TArray<UTimeSynthClip*> TimeSynthClips;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite, meta = (ClampMin = "0"))
	int32 CurrentClipIndex;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite)
	int32 SpectrumBarNum;

	//Weight for linear interpolation of spectrum data
	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite)
	float LinearInterpWeight;

	//Min and Max of Spectrum Fequencies
	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite)
	FVector2D SpectrumFequencyLimits;

	// What FFT bin-size to use. Smaller makes it more time-reactive but less accurate in frequency space.
	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite)
	ETimeSynthFFTSize FFTSize;

	//Arrays for Spectral Data processing
	TArray<float> LerpSpectralData;
	TArray<float> MaxSpectralData;

	//Player state
	EPlayerState PlayerState;
	//Current clip handle
	FTimeSynthClipHandle ClipHandle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//called by delegate from TimeSynthComponent every tick while playing clip. Argument is not used.
	UFUNCTION()
	void PlayerPlayback(float SynthPlaybackTimeSeconds);
};
