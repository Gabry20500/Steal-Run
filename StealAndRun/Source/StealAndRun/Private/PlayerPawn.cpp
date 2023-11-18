// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayerCollisionComponent"));
	RootComponent = PlayerCollisionComponent;
	PlayerCollisionComponent->SetSimulatePhysics(true);
	PlayerCollisionComponent->SetEnableGravity(true);
	PlayerCollisionComponent->SetLinearDamping(0.2f);

	MoveForce = BaseMoveForce;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);
}

void APlayerPawn::MoveRight(float AxisValue)
{
	if (AxisValue != 0.0f)
	{
		FVector Force = FVector(0.0f, AxisValue * MoveForce, 0.0f);
		PlayerCollisionComponent->AddForce(Force, NAME_None, true);
	}
	else 
	{
		if(!GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::LeftShift) || AxisValue == 0.0f)
			PlayerCollisionComponent->SetPhysicsLinearVelocity(FVector::ZeroVector);
	}
}

void APlayerPawn::OnShiftPressed()
{
	MoveForce = BaseMoveForce * ShiftMultiplayer;
	UE_LOG(LogTemp, Warning, TEXT("%f"), MoveForce);
}

void APlayerPawn::OnShiftReleased()
{
	MoveForce = BaseMoveForce;
	UE_LOG(LogTemp, Warning, TEXT("%f"), MoveForce);
}

