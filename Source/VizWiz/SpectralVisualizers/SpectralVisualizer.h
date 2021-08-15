// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpectralVisualizer.generated.h"

class USplineComponent;

// Make abstract and minimalapi for using only children, uncomment VIZWIZ_API if remove MinimalAPI spec
// Hide component settings from main BP (still available through component branch
UCLASS(Abstract, MinimalAPI, HideCategories=(InstancedStaticMeshComponent))
class /*VIZWIZ_API*/ ASpectralVisualizer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpectralVisualizer();
	// Called at the end of ExecuteConstruction, which calls the blueprint construction script.
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite)
	bool bUseTexture = false;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadWrite, meta = (EditCondition="!bUseTexture"))
	bool bUseHueShift = false;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	int32 SpectrumBarNum;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	float MagnitudeRatio;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	float BrightnessRatio;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	float BarScaleMin;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	float BarScaleMax;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	float BrightnessScaleMin;

	UPROPERTY(EditAnywhere, Category = "Audio", BlueprintReadOnly)
	float BrightnessScaleMax;

	// The instanced mesh component
	UPROPERTY(VisibleAnywhere, Category="InstancedStaticMeshComponent", BlueprintReadOnly)
	class UInstancedStaticMeshComponent* ISM;

	UPROPERTY(Category = Mesh, EditAnywhere, BlueprintReadWrite)
	UStaticMesh* InstancedMesh;

	UPROPERTY(Category = Mesh, EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* InstancedMeshMaterial;

	UPROPERTY(Category = Mesh, EditAnywhere, BlueprintReadWrite)
	FTransform InstancedMeshTransform;

	// Spline for the spectrum bars location
	UPROPERTY(Category = Spline, VisibleAnywhere, BlueprintReadOnly)
	USplineComponent* Spline;

	UPROPERTY(Category = Spline, EditAnywhere, BlueprintReadWrite)
	TArray<FVector> PointsUpVector;

	UPROPERTY() //looks as Garbage Collected without UPROPERTY (not sure)
	TArray<FVector> InitialScale;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called by Spectrum Update delegate
	UFUNCTION()
	void UpdateMeshes(const TArray<float>& InSpectralData, const float InEnvelope);
};
