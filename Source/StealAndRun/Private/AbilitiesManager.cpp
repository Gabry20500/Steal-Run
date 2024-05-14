
// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitiesManager.h"
#include "Abilities/HologramAbility.h"
#include "Abilities/HackingAbility.h"
//#include "Abilities/HologramAbility.h"

// Sets default values
AAbilitiesManager::AAbilitiesManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbilitiesManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbilitiesManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAbilitiesManager::SetAbility(AbilityEnum AbilityType)
{
	switch (AbilityType)
	{
		case AbilityEnum::None:
			CurrentAbility = nullptr;
			UE_LOG(LogTemp, Warning, TEXT("No ability is initialized. SetAbility"));
			break;
		
		case AbilityEnum::Hologram:
			CurrentAbility = NewObject<AHologramAbility>();
			AHologramAbility* HologramAbility = Cast<AHologramAbility>(CurrentAbility);
		
			UE_LOG(LogTemp, Warning, TEXT("Hologram is initialized. SetAbility"));
			break;
		
		case AbilityEnum::Hacking:
			CurrentAbility = NewObject<AHackingAbility>();
			AHackingAbility* HackingAbility = Cast<AHackingAbility>(CurrentAbility);
			HackingAbility->CurrentWorld = GetWorld();
			UE_LOG(LogTemp, Warning, TEXT("Hacking is initialized. SetAbility"));
			break;
	}
}

void AAbilitiesManager::UseAbility()
{
	CurrentAbility->UseAbility_Implementation();
}

void AAbilitiesManager::StopAbility()
{
	CurrentAbility->StopAbility_Implementation();
}



