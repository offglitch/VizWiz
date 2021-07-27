// Fill out your copyright notice in the Description page of Project Settings.


#include "SpectralVisualizer.h"
#include "TimeSynthComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASpectralVisualizer::ASpectralVisualizer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Declare the spacing between bars
	//TODO: Make it editable in real time. Expose
	SpectrumBarSpacing = 100.f;

	//Creating the timesynth component
	TimeSynthComponent = CreateDefaultSubobject<UTimeSynthComponent>("TimeSnythComponent");

	//Enabling spectral analysis allows the bars to "do something"
	TimeSynthComponent->bEnableSpectralAnalysis = true;

	//Root of the actor, all spectrum bars will attach to
	SetRootComponent(TimeSynthComponent);

	//for (int i = 1; i <= 20; ++i)

	//Creating the spectrum bars
	for (int i = 1; i <= 20; ++i)
	{
		/* tell the TS component to analyze the frequency of the bar
		look at frequencies X amount at a time 50, 100, 150, 200
		each of the bars is going to listen to that particular frequency */
		TimeSynthComponent->FrequenciesToAnalyze.Add(i * 50);

		//Naming conventions and logging for frequencies
		FString SpectrumBarName = FString::Printf(TEXT("SpectrumBar%dHz"), i * 50);

		UStaticMeshComponent* SpectrumBar = CreateDefaultSubobject<UStaticMeshComponent>(*SpectrumBarName);
		//attach spectrum bar to TS component
		SpectrumBar->SetupAttachment(TimeSynthComponent);
		//set mesh for the bar
		SpectrumBar->SetStaticMesh(SpectrumBarMesh);
		//offset each bar (moving along the x axis?)
		//move appropriately along a line 
		SpectrumBar->SetRelativeLocation(FVector(i * SpectrumBarSpacing, 0.f, 0.f));
		SpectrumBars.Add(SpectrumBar);

	}



}

// Called when the game starts or when spawned
void ASpectralVisualizer::BeginPlay()
{
	Super::BeginPlay();

	Refresh();

	//right now TimeSynthComponent gets triggered on runtime
	//TODO: trigger on collision for further prototyping
	TimeSynthComponent->PlayClip(TimeSynthClip);

}

void ASpectralVisualizer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	//editing property, calling super function to change property
	//note to self: always call super otherwise nothing will change :)
	Super::PostEditChangeProperty(PropertyChangedEvent);

	//refresh the spectral visualizer so that when the spacing between the spectrum bars it will react and start moving them away from each other
	Refresh();
}


/*
	This function refreshes the spacing between meshes or spectrum bars
*/
void ASpectralVisualizer::Refresh()
{
	for (int i = 0; i <= 20; ++i)
	{
		//check if the index is valid
		if (SpectrumBars.IsValidIndex(i))
		{
			UStaticMeshComponent* SpectrumBar = SpectrumBars[i];
			//static mesh change handler
			SpectrumBar->SetStaticMesh(SpectrumBarMesh);
			SpectrumBar->SetRelativeLocation(FVector((i + 1) * SpectrumBarSpacing, 0.f, 0.f));
		}

	}
}

// Called every frame (make the bars actually bounce up and down)
void ASpectralVisualizer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*	
		iterate over the spectral data and the audio file
		SpecData is just data about frequency and the amplitude of that frequency
		i.e. if theres bass, then how much bass is there or a piano note what's the amplitude of that frequency
	*/

	for (auto SpecData : TimeSynthComponent->GetSpectralData())
	{
		/*
			need to get the spectrum bar for the frequency we're looking at
			UStaticMeshComponent* SpectrumBar = SpecData.FrequencyHz;
			since we're looking at frequencies X at a time, we can divide by X to get the index of the spectrum bar for that frequency
		*/

		UStaticMeshComponent* SpectrumBar = SpectrumBars[SpecData.FrequencyHz / 50.f - 1];

		//make the Z scale of the bar change depending on the frequency
		//TODO: Play around different orientations and axis
		//get the bar scale and magnitude of frequency

		FVector BarScale = SpectrumBar->GetComponentScale();
		BarScale.Z = 1.f + SpecData.Magnitude / 5.f;
		//interpolating because otherwise it looks too wonky
		SpectrumBar->SetWorldScale3D(FMath::VInterpTo(SpectrumBar->GetComponentScale(), BarScale, DeltaTime, 5.f));
	}


}

