// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractablePlatform.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AInteractablePlatform::AInteractablePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void AInteractablePlatform::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComponent = FindComponentByClass<UStaticMeshComponent>();
}


void AInteractablePlatform::SetPlayerVelocity(FVector PlayerVel, APlayerCharacter* PlayerRef)
{
	PlayerVelocity = PlayerVel;
	Player = PlayerRef;
}

// Called every frame
void AInteractablePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(isInFalling == false)
	{
		if(PlayerVelocity.Z > 0 && Player->GetActorLocation().Z < GetActorLocation().Z)
		{
			MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
			Player->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
			Player->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 50.f));
			//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AInteractablePlatform::ResetPlatform, TimeToGoUp, false);
		}
	}
}

void AInteractablePlatform::Interact_Implementation()
{
	isInFalling = true;
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AInteractablePlatform::ResetPlatform, TimeToReset, false);
}

void AInteractablePlatform::ResetPlatform()
{
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	isInFalling = false;
}

