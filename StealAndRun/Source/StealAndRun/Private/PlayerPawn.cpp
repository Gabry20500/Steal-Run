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
	TargetMoveForce = BaseMoveForce;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);
}

void APlayerPawn::MoveRight(float AxisValue)
{
	FVector Force = FVector(0.0f, AxisValue * MoveForce, 0.0f);
	PlayerCollisionComponent->AddForce(Force, NAME_None, true);
}

void APlayerPawn::OnShiftPressed()
{
	TargetMoveForce = BaseMoveForce * ShiftMultiplayer;
	bIsShiftPressed = true;
	UE_LOG(LogTemp, Log, TEXT("%s"), bIsShiftPressed ? TEXT("true") : TEXT("false"));
}

void APlayerPawn::OnShiftReleased()
{
	bIsShiftPressed = false;
	UE_LOG(LogTemp, Log, TEXT("%s"), bIsShiftPressed ? TEXT("true") : TEXT("false"));
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector Velocity = PlayerCollisionComponent->GetComponentVelocity();
	//UE_LOG(LogTemp, Log, TEXT("Velocity: %s"), *Velocity.ToString());
	
	float CurrentInterpSpeed = bIsShiftPressed ? InterpSpeed : FasterInterpSpeed;

	if (bIsShiftPressed)
	{
		MoveForce = FMath::FInterpTo(MoveForce, TargetMoveForce, DeltaTime, CurrentInterpSpeed);
	}
	else
	{
		MoveForce = FMath::FInterpTo(MoveForce, BaseMoveForce, DeltaTime, CurrentInterpSpeed);
	}
	
}

