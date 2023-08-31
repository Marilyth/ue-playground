// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat CurrentQuatRotation = FQuat(GetActorRotation());

	float DeltaRotation = (DeltaTime / CycleInSeconds) * 2 * PI;
	FQuat NewQuatRotation = FQuat(FVector(0, 1, 0), DeltaRotation);

	AddActorLocalRotation(NewQuatRotation);
}

