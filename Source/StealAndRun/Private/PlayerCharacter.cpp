
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


APlayerCharacter::APlayerCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 1.0f;

	Multi = 2.0f;
	SlideTime = 1.0f;
	bPressedJump = false;
	bisRunning = false;
}


void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(GetCharacterMovement())
	{
		BaseWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	}
}


// void APlayerCharacter::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// 	if(!bisRunning || !InputReceived() && GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->Velocity.SizeSquared() > 0.1f)
// 	{
// 		if(GetCharacterMovement()->MaxWalkSpeed > BaseWalkSpeed)
// 		{
// 			GetCharacterMovement()->Velocity *= 0.8f;
// 		}
// 	}
// }

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Controllo del cambio di direzione a mezz'aria
	if (!GetCharacterMovement()->IsFalling())
	{
		// Controllo dell'input per il cambio di direzione
		float RightValue = InputComponent->GetAxisValue("MoveRight");
		if (RightValue != 0.0f)
		{
			FVector Direction = GetActorRightVector() * RightValue;
			AddMovementInput(Direction);
		}
	}
}


void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	// InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	// InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump);
	InputComponent->BindAction("Shift", IE_Pressed, this, &APlayerCharacter::StartRun);
	InputComponent->BindAction("Shift", IE_Released, this, &APlayerCharacter::StopRun);
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
		if (GetCharacterMovement()->MaxWalkSpeed >= BaseWalkSpeed)
		{
			float NewWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
			float DeltaSpeed = (BaseWalkSpeed * Multi - BaseWalkSpeed) / (SlideTime / GetWorld()->GetDeltaSeconds());

			while (NewWalkSpeed >= BaseWalkSpeed)
			{
				NewWalkSpeed -= DeltaSpeed;
				GetCharacterMovement()->MaxWalkSpeed = NewWalkSpeed;
			}

			GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
		}
	}
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

