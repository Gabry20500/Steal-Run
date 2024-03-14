
#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

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

	PlySphereComponent= Cast<USphereComponent>(GetComponentByClass(USphereComponent::StaticClass()));
	if(PlySphereComponent)
	{
		PlySphereComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnOverlapBegin);
		UE_LOG(LogTemp, Warning, TEXT("PlySphereComponent is initialized."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlySphereComponent is not initialized."));
	}
	
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

	if(!bIsInteracting)
	{
		ObjInteractable = nullptr;
	}
	if(!bIsCollectable)
	{
		ObjCollectable = nullptr;
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

	UPaperFlipbookComponent* FlipboardComponent = Cast<UPaperFlipbookComponent>(GetComponentByClass(UPaperFlipbookComponent::StaticClass()));
	USphereComponent* SphereComponent = Cast<USphereComponent>(GetComponentByClass(USphereComponent::StaticClass()));
	if (AxisValue > 0.0f)
	{
		if(PlayerDirection!=EPlayerDirection::Right)
		{
			FlipboardComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
			SphereComponent->SetRelativeLocation(FVector(30.0f, SphereComponent->GetRelativeLocation().Y, SphereComponent->GetRelativeLocation().Z));
		}
		
		PlayerDirection = EPlayerDirection::Right;
	}
	else if (AxisValue < 0.0f)
	{
		if(PlayerDirection!=EPlayerDirection::Left)
		{
			FlipboardComponent->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
			SphereComponent->SetRelativeLocation(FVector(-30.0f, SphereComponent->GetRelativeLocation().Y, SphereComponent->GetRelativeLocation().Z));
		}

		PlayerDirection = EPlayerDirection::Left;
	}
}

void APlayerCharacter::Interact()
{
	if(bIsInteracting)
	{
		if(ObjInteractable->Implements<UIInteractable>())
			IIInteractable::Execute_Interact(ObjInteractable);
	}else if(bIsCollectable)
	{
		Score += IICollectable::Execute_GetPoints(ObjCollectable);
		UE_LOG(LogTemp, Warning, TEXT("%d"), Score);
		IICollectable::Execute_Collect(ObjCollectable);
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
}

void APlayerCharacter::GetCollectableObject(AActor* Actor)
{
	ObjCollectable = Actor;
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

void APlayerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (OtherComp->GetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3) == ECollisionResponse::ECR_Block || OtherComp->GetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3) == ECollisionResponse::ECR_Overlap)
		{
			bIsOverlappingWithMantle = true;
			UE_LOG(LogTemp, Warning, TEXT("Overlapping with actor: %s"), *OtherActor->GetName());

			// Get the BoxComponent of the other actor
			UBoxComponent* OtherActorBoxComponent = Cast<UBoxComponent>(OtherActor->GetComponentByClass(UBoxComponent::StaticClass()));

			if (OtherActorBoxComponent)
			{
				// Get the location of the BoxComponent
				MantleLocation = OtherActorBoxComponent->GetComponentLocation();

				// Now BoxComponentLocation is a vector representing the location of the BoxComponent of the other actor
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("OtherActor does not have a BoxComponent."));
			}
		}
	}
}

