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

	Multi = 2.0f;
	bPressedJump = false;
	bisRunning = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(GetCharacterMovement())
	{
		BaseWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	}
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!bisRunning || !InputReceived() && GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->Velocity.SizeSquared() > 0.1f)
	{
		if(GetCharacterMovement()->MaxWalkSpeed > BaseWalkSpeed)
		{
			GetCharacterMovement()->Velocity *= 0.8f;
		}
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);
	InputComponent->BindAction("Shift", IE_Pressed, this, &APlayerCharacter::StartRun);
	InputComponent->BindAction("Shift", IE_Released, this, &APlayerCharacter::StopRun);
	InputComponent->BindAction("Slide", IE_Pressed, this, &APlayerCharacter::StartSlide);
}

void APlayerCharacter::MoveRight(float Axisvalue)
{
	FVector Direction = FVector(0.0f, -1.0f, 0.0f);
	AddMovementInput(Direction, Axisvalue);
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

	if(GetCharacterMovement())
		GetCharacterMovement()->MaxWalkSpeed *= Multi;
}

void APlayerCharacter::StopRun()
{
	bisRunning = false;
	if(GetCharacterMovement())
	{
		if (GetCharacterMovement()->MaxWalkSpeed > BaseWalkSpeed)
		{
			float NewWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;;
			float DeltaSpeed = (BaseWalkSpeed * Multi - BaseWalkSpeed) / (SlideTime / GetWorld()->GetDeltaSeconds());

			while (NewWalkSpeed >= BaseWalkSpeed)
			{
				NewWalkSpeed -= DeltaSpeed;
				GetCharacterMovement()->MaxWalkSpeed = NewWalkSpeed * Multi;
			}

			GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
		}
	}
}

void APlayerCharacter::StartSlide()
{
	if(!GetCharacterMovement()->IsMoveInputIgnored() || bIsSliding)
	{
		return;
	}

	bIsSliding = true;

	if(GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed *= SlideSpeedMultiplier;
	}

	GetWorldTimerManager().SetTimer(SlideTimerHandle, this, &APlayerCharacter::StopSlide, SlideDuration, false);
}

void APlayerCharacter::StopSlide()
{
	if(GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed/= SlideSpeedMultiplier;
	}

	bIsSliding = false;
}

bool APlayerCharacter::InputReceived()
{
	float RightValue = InputComponent->GetAxisValue("MoveRight");

	if(FMath::Abs(RightValue) > 0.1f)
	{
		return true;
	}

	return false;
}

