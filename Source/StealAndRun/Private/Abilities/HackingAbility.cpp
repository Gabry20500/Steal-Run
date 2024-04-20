// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/HackingAbility.h"
#include "Kismet/GameplayStatics.h"

#include "EngineUtils.h"
#include "IHackerable.h"

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
	
	TArray<AActor*> TagOwners;
	UGameplayStatics::GetAllActorsWithTag( CurrentWorld,"Hackable", TagOwners);

	if(TagOwners.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No object to hack"));
		return;
	}
	else
	{
		for (AActor* TagOwner : TagOwners)
		{
			IIHackerable* Hackerable = Cast<IIHackerable>(TagOwner);
			if(Hackerable)
			{
				Hackerable->Disable();
			}
			UE_LOG(LogTemp, Warning, TEXT("Hacking %s"), *TagOwner->GetName());
		}
	}
	
}

void AHackingAbility::StopAbility_Implementation()
{
}
