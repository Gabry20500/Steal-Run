// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/HologramAbility.h"

#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"


AHologramAbility::AHologramAbility()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHologramAbility::BeginPlay()
{
	Super::BeginPlay();
}

void AHologramAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHologramAbility::UseAbility_Implementation()
{
	//DrawMousePosition();
	UE_LOG(LogTemp, Warning, TEXT("Use Hologram Ability"));
}

void AHologramAbility::StopAbility_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Stop Hologram Ability"));
}

void AHologramAbility::DrawMousePosition()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(CurrentWorld, 0);
	FVector StartLocation, EndLocation;

	
	if(PlayerController == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is null."));
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is ok."));
		StartLocation = PlayerController->GetPawn()->GetActorLocation();
	}

	float MouseX, MouseY;
	PlayerController->GetMousePosition(MouseX, MouseY);

	FVector WorldLocation;
	FVector WorldDirection;
	PlayerController->DeprojectScreenPositionToWorld(MouseX, MouseY, WorldLocation, WorldDirection);

	FVector NewLocation = FVector(StartLocation.X, WorldLocation.Y, WorldLocation.Z);

	
	APlayerCharacter *PlayerCharacter = Cast<APlayerCharacter>(PlayerController->GetPawn());
	//FVector NewRotation = PlayerCharacter->GetDirection();
	FVector NewRotation = PlayerCharacter->GetActorForwardVector();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *NewRotation.ToString());
	
	EndLocation = NewLocation + NewRotation * 1000; // 200 is the distance of the line trace
	
	//Create a FHitResult to store the hit result
	FHitResult HitResult;

	// Create a FCollisionQueryParams to specify additional parameters
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this); // Ignore the actor that is doing the line trace

	PlayerController->bShowMouseCursor = true;
	
	// Perform the line trace
	bool bHit = CurrentWorld->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);

	if (bHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit something"));
		// If the line trace hit something, draw a red line
		DrawDebugLine(CurrentWorld, StartLocation, EndLocation, FColor::Red, false, 100, 0, 1);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Did not hit anything"));
		// If the line trace did not hit anything, draw a green line
		DrawDebugLine(CurrentWorld, StartLocation, EndLocation, FColor::Green, false, 100, 0, 1);
	}
}

