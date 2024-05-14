// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/HologramAbility.h"

// Sets default values
AHologramAbility::AHologramAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHologramAbility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHologramAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHologramAbility::UseAbility_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Hologram is used."));
}

void AHologramAbility::StopAbility_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Hologram is stopped."));
}