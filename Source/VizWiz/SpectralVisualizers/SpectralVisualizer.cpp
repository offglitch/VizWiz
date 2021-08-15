// Fill out your copyright notice in the Description page of Project Settings.

#include "SpectralVisualizer.h"
#include "SpectralPlayer.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASpectralVisualizer::ASpectralVisualizer()
	: SpectrumBarNum(0)
	, MagnitudeRatio(1.f)
	, BrightnessRatio(5.f)
	, BarScaleMin(0.1f)
	, BarScaleMax(4.f)
	, BrightnessScaleMin(0.25f)
	, BrightnessScaleMax(10.f)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Creating the spline
	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SetRootComponent(Spline);
	//filling array and fixing spline points
	const float poinstNum = Spline->GetNumberOfSplinePoints();
	PointsUpVector.Empty();
	for (int i = 0; i < poinstNum; ++i) {
		PointsUpVector.Add(Spline->GetUpVectorAtSplinePoint(i, ESplineCoordinateSpace::Local));
	}

	//Creating the InstancedStaticMeshComponent
	ISM = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMeshComponent"));
	ISM->SetupAttachment(Spline);
	ISM->bUseDefaultCollision = false; //no collisions
}

// Called when the game starts or when spawned
void ASpectralVisualizer::BeginPlay()
{
	Super::BeginPlay();
	//Check Player exists and is not CDO
	if (ASpectralPlayer::PlayerInstance->IsValidLowLevel() && !ASpectralPlayer::PlayerInstance->HasAnyFlags(RF_ClassDefaultObject)) {
		//bind function
		ASpectralPlayer::PlayerInstance->OnSpectrumUpdate.AddDynamic(this, &ASpectralVisualizer::UpdateMeshes);
		//getter
		SpectrumBarNum = ASpectralPlayer::PlayerInstance->GetSpectrumBarNum();
		//construction with updated Bar Num
		OnConstruction(GetActorTransform());
	} else {
		// Error msg
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("There is no SpectralPlayer!!!"));
	}
}

void ASpectralVisualizer::OnConstruction(const FTransform& Transform)
{
	// To configure the visualizer before launching
	Super::OnConstruction(Transform);
	//ISM setup
	ISM->ClearInstances();
	ISM->SetStaticMesh(InstancedMesh);
	ISM->SetMaterial(0, InstancedMeshMaterial);
	InitialScale.Init(FVector::OneVector, SpectrumBarNum);

	//Updating Spline with fixing new points UpVector
	while (Spline->GetNumberOfSplinePoints() > PointsUpVector.Num()) //adding array elements from spline points data
	{
		PointsUpVector.Add(Spline->GetUpVectorAtSplinePoint(PointsUpVector.Num() - 1, ESplineCoordinateSpace::Local));
	}
	const int32 pointsNum = Spline->SplineCurves.Position.Points.Num();
	const int32 arrayNum  = PointsUpVector.Num();
	if (pointsNum < arrayNum) //removing unnecessary array elements
	{
		PointsUpVector.RemoveAt(pointsNum, arrayNum - pointsNum);
	}
	for (int32 i = 0; i < pointsNum; ++i) //setting spline points data from array
	{
		Spline->SetUpVectorAtSplinePoint(i, PointsUpVector[i], ESplineCoordinateSpace::Local, false);
	}
	Spline->UpdateSpline();

	//Creating the spectrum bars
	// if Bars > 0 and ISM has initial static mesh
	if (SpectrumBarNum > 0 && ISM->GetStaticMesh()) {
		//spline distance between meshes in range 0-1 (bool converts to int 0 or 1)
		const float splineStep = 1.f / (SpectrumBarNum - !Spline->IsClosedLoop());
		const bool bShift = bUseTexture || bUseHueShift;
		//Primitive Custom Data used for material param changing (1 or 2 slots)
		ISM->NumCustomDataFloats = 1 + bShift;
		for (int32 i = 0; i < SpectrumBarNum; ++i) {
			//Transform of point on spline (Time = 0-1, can be shifted by Distance, real pos is (Time / Duration * GetSplineLength()) 
			FTransform barTransform = Spline->GetTransformAtTime(splineStep * i, ESplineCoordinateSpace::Local, true);
			//Adding our mesh settings
			barTransform.Accumulate(InstancedMeshTransform);
			//Normalize for error avoiding
			barTransform.NormalizeRotation();
			//Adding mesh
			ISM->AddInstance(barTransform);
			//Saving initial scale of bar
			InitialScale[i] = barTransform.GetScale3D();
			//set material param shift
			if (bShift) ISM->SetCustomDataValue(i, 1, (float)(i) / SpectrumBarNum);
			ISM->SetCustomDataValue(i, 0, 10.f * i / SpectrumBarNum);
		}
	}
}

void ASpectralVisualizer::UpdateMeshes(const TArray<float>& InSpectralData, const float InEnvelope)
{
	if (ISM->GetInstanceCount() == SpectrumBarNum) {
		for (int32 i = 0; i < SpectrumBarNum; ++i) {
			FTransform curTransform;
			ISM->GetInstanceTransform(i, curTransform); //get current mesh FTransform
			curTransform.SetScale3D(InitialScale[i]);   //replace its scale

			const float magnitude = InSpectralData[i];
			//make the Z scale of the bar change depending on the frequency
			const float scaleZ = FMath::Min(BarScaleMin + magnitude * MagnitudeRatio, BarScaleMax);
			curTransform.MultiplyScale3D(FVector(1.f, 1.f, scaleZ));
			//make the brightness of the bar change depending on the frequency
			const float scaleBrightness = FMath::Min(BrightnessScaleMin + magnitude * BrightnessRatio, BrightnessScaleMax);
			//changing material param, that scale color
			ISM->SetCustomDataValue(i, 0, scaleBrightness);
			//changing Transform in LocalSpace with updating on last iteration only
			ISM->UpdateInstanceTransform(i, curTransform, false, i == SpectrumBarNum - 1);
		}
	}
}
