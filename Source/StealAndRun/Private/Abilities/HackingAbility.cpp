// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/HackingAbility.h"

#include "EngineUtils.h"

// Sets default values
AHackingAbility::AHackingAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHackingAbility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHackingAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHackingAbility::UseAbility_Implementation()
{
	TArray<AActor*> TagOwners = GetAllActorsWithTag("SCamera");
for (AActor* TagOwner : TagOwners)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hacking %s"), *TagOwner->GetName());
	}
}

void AHackingAbility::StopAbility_Implementation()
{
}

TArray<AActor*> AHackingAbility::GetAllActorsWithTag(FName Tag)
{
	TArray<AActor*> Result;
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		if (It->ActorHasTag(Tag))
		{
			Result.Add(*It);
		}
	}
	return Result;
}