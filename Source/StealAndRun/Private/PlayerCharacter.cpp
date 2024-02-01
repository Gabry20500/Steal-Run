
#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

APlayerCharacter::APlayerCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->AirControl = 0.2f;

	Multi = 2.0f;
	SlideTime = 1.0f;
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
	InputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::StopRun);
	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
}

void APlayerCharacter::OpenDoor(UBoxComponent* HitBoxComponent)
{
	if (HitBoxComponent)
	{
		FVector TargetLocation = HitBoxComponent->GetComponentLocation();
		SetActorLocation(TargetLocation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Reference a TargetBoxComponent nulla in OpenDoor"));
	}
}


void APlayerCharacter::MoveRight(float AxisValue)
{
	FVector Direction = FVector(0.0f, 1.0f, 0.0f);
	AddMovementInput(Direction, AxisValue);

	UPaperFlipbookComponent* FlipbookComponent = Cast<UPaperFlipbookComponent>(GetComponentByClass(UPaperFlipbookComponent::StaticClass()));
	if (AxisValue > 0.0f)
	{
		if(PlayerDirection!=EPlayerDirection::Right)
			FlipbookComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		
		PlayerDirection = EPlayerDirection::Right;
	}
	else if (AxisValue < 0.0f)
	{
		if(PlayerDirection!=EPlayerDirection::Left)
			FlipbookComponent->SetWorldRotation(FRotator(0.0f, 270.0f, 0.0f));

		PlayerDirection = EPlayerDirection::Left;
	}
}

void APlayerCharacter::Interact()
{
	if(bIsInteracting)
	{
		ObjInteractableInterface->Interact_Implementation();
	}
}


void APlayerCharacter::OnJumpStart()
{
	
}


void APlayerCharacter::OnJumpEnd()
{

}


void APlayerCharacter::GetInteractableObject(AActor* Actor)
{
	ObjInteractable = Actor;
	ObjInteractableInterface = Cast<IIInteractable>(Actor);
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

