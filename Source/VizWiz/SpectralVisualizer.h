// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpectralVisualizer.generated.h"

UCLASS()
class VIZWIZ_API ASpectralVisualizer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpectralVisualizer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Called when a property is changed, overriding because I want to seamlessly change spectrum bar spacing in order to spread the bars out
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	void Refresh();


	//This is the core of the actor, the TimeSynth component
	UPROPERTY(EditAnywhere, Category = "Audio")
	class UTimeSynthComponent* TimeSynthComponent;

	//TSClip represents that piece of audio from TSComponent 
	UPROPERTY(EditAnywhere, Category = "Audio")
	class UTimeSynthClip* TimeSynthClip;

	//Creating an array of meshes to bounce up and down, using the static mesh component
	//These bars just represent the different frequencies in an audio file
	UPROPERTY(EditAnywhere, Category = "Audio")
	TArray<UStaticMeshComponent*> SpectrumBars;

	//Allows usage of any mesh
	//TODO: Play around with different meshes ie sphere, pyramids ets. Idea: procedurally generated meshes?
	UStaticMesh* SpectrumBarMesh;

	//The spacing between each bar, allows the bars to move away from each other
	UPROPERTY(EditAnywhere, Category = "Audio")
	float SpectrumBarSpacing;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
