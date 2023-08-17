// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowPlayerActor.h"

// Sets default values
AFollowPlayerActor::AFollowPlayerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AFollowPlayerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFollowPlayerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get player camera rotation.
	FRotator playerRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();

	// Get player camera location.
	FVector playerVector = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	// Set current actor location and rotation to player location and rotation.
	SetActorLocation(playerVector);
	SetActorRotation(playerRotation);

	// Log current player location and rotation.
	UE_LOG(LogTemp, Warning, TEXT("Player Location: %s"), *playerVector.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Player Rotation: %s"), *playerRotation.ToString());

	// Log current actor location and rotation.
	UE_LOG(LogTemp, Warning, TEXT("Actor Location: %s"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Actor Rotation: %s"), *GetActorRotation().ToString());
}

