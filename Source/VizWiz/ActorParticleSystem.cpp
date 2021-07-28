// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorParticleSystem.h"

// Sets default values
AActorParticleSystem::AActorParticleSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorParticleSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorParticleSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

