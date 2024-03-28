// Fill out your copyright notice in the Description page of Project Settings.


#include "Hologram_Ability.h"

// Sets default values
AHologram_Ability::AHologram_Ability()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHologram_Ability::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHologram_Ability::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHologram_Ability::Use_Implementation()
{
	
}

void AHologram_Ability::Stop_Implementation()
{
	
}

