// Fill out your copyright notice in the Description page of Project Settings.
#include "InteractableDoor.h"

#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInteractableDoor::AInteractableDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableDoor::BeginPlay()
{
	Super::BeginPlay();
	PlayerRef = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	StaticMeshComponent = GetComponentByClass<UStaticMeshComponent>();
}

// Called every frame
void AInteractableDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsPlayerNear)
	{
		//Interact_Implementation();
	}

}

void AInteractableDoor::Interact_Implementation()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInteractableDoor::StaticClass(), FoundActors);

	for (AActor* FoundActor : FoundActors)
	{
		if(FoundActor->ActorHasTag(NextDoorTag))
		{
			UBoxComponent* HitBoxComponent = FoundActor->GetComponentByClass<UBoxComponent>();
	
			if(HitBoxComponent)
			{
				if(PlayerRef)
				{
					PlayerRef->OpenDoor(HitBoxComponent);
				}
			}
		}
	}
	bIsPlayerNear = false;
}

