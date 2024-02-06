// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractablePlatform.h"

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

// Called every frame
void AInteractablePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractablePlatform::Interact_Implementation()
{
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AInteractablePlatform::ResetPlatform, TimeToReset, false);
}

void AInteractablePlatform::ResetPlatform()
{
	MeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
}

