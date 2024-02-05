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
	StaticMeshComponent = GetComponentByClass<UStaticMeshComponent>();

	if (StaticMeshComponent)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Il componente UStaticMeshComponent è presente nell'attore padre"));
	}
	else
	{
		// Il componente richiesto non è presente nell'attore
		UE_LOG(LogTemp, Warning, TEXT("Il componente UStaticMeshComponent non è presente nell'attore padre"));
	}
	
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
	

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	
	FVector Position = StaticMeshComponent->GetComponentLocation();
	FVector EndPos = GetActorForwardVector() * 100000 + Position;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, GetActorLocation(), EndPos,ECC_EngineTraceChannel2 , CollisionParams);
	if(bHit)
	{
		AActor* HitActor = HitResult.GetActor();
		UBoxComponent* HitBoxComponent = HitActor->GetComponentByClass<UBoxComponent>();

		if(HitBoxComponent)
		{
			APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

			if(PlayerCharacter)
			{
				PlayerCharacter->OpenDoor(HitBoxComponent);
			}
		}
	}
	bIsPlayerNear = false;
}

