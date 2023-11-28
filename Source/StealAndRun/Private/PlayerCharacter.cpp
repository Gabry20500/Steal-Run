// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	bPressedJump = false;
	bisRunning = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);
	InputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::StopRun);
}

void APlayerCharacter::MoveRight(float Axisvalue)
{
	FVector Direction = FVector(0.0f, -1.0f, 0.0f);
	if (bisRunning) 
	{
		AddMovementInput(Direction, (Axisvalue * 12) * multi);
	}
	else 
	{
		AddMovementInput(Direction, Axisvalue * 12);
	}

}

void APlayerCharacter::StartJump()
{
	bPressedJump = true;
	Jump();
}

void APlayerCharacter::StopJump()
{
	bPressedJump = false;
	StopJumping();
}

void APlayerCharacter::StartRun()
{
	bisRunning = true;
}

void APlayerCharacter::StopRun()
{
	bisRunning = false;
}

