
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


APlayerCharacter::APlayerCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	//GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

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


void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsJumping && GetWorld()->GetTimeSeconds() - JumpStartTime < MaxJumpDuration)
	{
		FVector JumpVelocity = FVector(0.0f, 0.0f, JumpZVelocity * DeltaTime);
		LaunchCharacter(JumpVelocity, false, false);
	}
	else
	{
		bIsJumping = false;
	}



	
	if(!bisRunning || !InputReceived() && GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->Velocity.SizeSquared() > 0.1f)
	{
		if(GetCharacterMovement()->MaxWalkSpeed > BaseWalkSpeed)
		{
			GetCharacterMovement()->Velocity *= 0.8f;
		}
	}
}


void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	// InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::OnJumpStart);
	// InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::OnJumpEnd);
	InputComponent->BindAction("Shift", IE_Pressed, this, &APlayerCharacter::StartRun);
	InputComponent->BindAction("Shift", IE_Released, this, &APlayerCharacter::StopRun);
}


void APlayerCharacter::MoveRight(float Axisvalue)
{
	FVector Direction = FVector(0.0f, -1.0f, 0.0f);
	AddMovementInput(Direction, Axisvalue);
}


void APlayerCharacter::OnJumpStart()
{
	bIsJumping = true;
	JumpStartTime = GetWorld()->GetTimeSeconds();
}


void APlayerCharacter::OnJumpEnd()
{
	bIsJumping  = false;
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

