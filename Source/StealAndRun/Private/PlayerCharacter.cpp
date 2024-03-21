
#include "PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

// Constructor for the PlayerCharacter class
APlayerCharacter::APlayerCharacter()
{
  PrimaryActorTick.bCanEverTick = true;

 // Set the character's movement properties
 GetCharacterMovement()->bOrientRotationToMovement = true;
 GetCharacterMovement()->AirControl = 0.2f;

 // Initialize running properties
 Multi = 2.0f;
 SlideTime = 1.0f;
 bisRunning = false;
}

// Called when the game starts or when the player character is spawned
void APlayerCharacter::BeginPlay()
{
 Super::BeginPlay();

 // Initialize the player's sphere component
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

 // Store the base walk speed
 if(GetCharacterMovement())
 {
  BaseWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
 }
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
 Super::Tick(DeltaTime);

 // Handle running and interaction with objects
 if(!bisRunning || !InputReceived() && GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->Velocity.SizeSquared() > 0.1f)
 {
  if(GetCharacterMovement()->MaxWalkSpeed > BaseWalkSpeed)
  {
   GetCharacterMovement()->Velocity *= 0.8f;
  }
 }

 // Reset interactable and collectable objects if not interacting or collecting
 if(!bIsInteracting)
 {
  ObjInteractable = nullptr;
 }
 if(!bIsCollectable)
 {
  ObjCollectable = nullptr;
 }
}

// Setup player input bindings
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
 Super::SetupPlayerInputComponent(PlayerInputComponent);

 // Bind movement and action inputs
 InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
 InputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::StartRun);
 InputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::StopRun);
 InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
}

// Method to open a door
void APlayerCharacter::OpenDoor(UBoxComponent* HitBoxComponent)
{
 // Check if the HitBoxComponent is not null
 if (HitBoxComponent)
 {
  // Get the location of the HitBoxComponent
  FVector TargetLocation = HitBoxComponent->GetComponentLocation();
  
  // Set the player's location to the location of the HitBoxComponent
  SetActorLocation(TargetLocation);
 }
 else
 {
  // Log a warning message if the HitBoxComponent is null
  UE_LOG(LogTemp, Warning, TEXT("Reference a TargetBoxComponent nulla in OpenDoor"));
 }
}

// Method to move the player to the right
void APlayerCharacter::MoveRight(float AxisValue)
{
 // Define the direction of movement
 FVector Direction = FVector(0.0f, 1.0f, 0.0f);
 
 // Add movement input in the defined direction
 AddMovementInput(Direction, AxisValue);

 // Get the player's FlipboardComponent and SphereComponent
 UPaperFlipbookComponent* FlipboardComponent = Cast<UPaperFlipbookComponent>(GetComponentByClass(UPaperFlipbookComponent::StaticClass()));
 USphereComponent* SphereComponent = Cast<USphereComponent>(GetComponentByClass(USphereComponent::StaticClass()));
 
 // Check if the AxisValue is greater than 0.0f
 if (AxisValue > 0.0f)
 {
  // If the player is not already moving to the right
  if(PlayerDirection!=EPlayerDirection::Right)
  {
   // Set the rotation of the FlipboardComponent and the location of the SphereComponent
   FlipboardComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
   SphereComponent->SetRelativeLocation(FVector(30.0f, SphereComponent->GetRelativeLocation().Y, SphereComponent->GetRelativeLocation().Z));
  }

  // Set the player's direction to right
  PlayerDirection = EPlayerDirection::Right;
 }
 else if (AxisValue < 0.0f)
 {
  // If the player is not already moving to the left
  if(PlayerDirection!=EPlayerDirection::Left)
  {
   // Set the rotation of the FlipboardComponent and the location of the SphereComponent
   FlipboardComponent->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
   SphereComponent->SetRelativeLocation(FVector(-30.0f, SphereComponent->GetRelativeLocation().Y, SphereComponent->GetRelativeLocation().Z));
  }

  // Set the player's direction to left
  PlayerDirection = EPlayerDirection::Left;
 }
}

// Method to handle the player's interaction with objects
void APlayerCharacter::Interact()
{
 // Check if the player is interacting
 if(bIsInteracting)
 {
  // If the ObjInteractable implements the IInteractable interface
  if(ObjInteractable->Implements<UIInteractable>())
   // Execute the Interact method of the ObjInteractable
   IIInteractable::Execute_Interact(ObjInteractable);
 }
 else if(bIsCollectable)
 {
  // If the player is collectable, increase the score by the points of the ObjCollectable
  Score += IICollectable::Execute_GetPoints(ObjCollectable);
  
  // Log the current score
  UE_LOG(LogTemp, Warning, TEXT("%d"), Score);
  
  // Execute the Collect method of the ObjCollectable
  IICollectable::Execute_Collect(ObjCollectable);
 }
}

// Method to get the interactable object
void APlayerCharacter::GetInteractableObject(AActor* Actor)
{
 // Set the ObjInteractable to the provided Actor
 ObjInteractable = Actor;
}

// Method to get the collectable object
void APlayerCharacter::GetCollectableObject(AActor* Actor)
{
 // Set the ObjCollectable to the provided Actor
 ObjCollectable = Actor;
}

// Method to start running
void APlayerCharacter::StartRun()
{
 // Set bisRunning to true
 bisRunning = true;

 // If the character's movement component is not null
 if(GetCharacterMovement())
  // Increase the MaxWalkSpeed of the character's movement component by the Multi
  GetCharacterMovement()->MaxWalkSpeed *= Multi;
}

// Method to stop running
void APlayerCharacter::StopRun()
{
 // Set bisRunning to false
 bisRunning = false;
 
 // If the character's movement component is not null
 if(GetCharacterMovement())
 {
  // If the MaxWalkSpeed of the character's movement component is greater than or equal to the BaseWalkSpeed
  if (GetCharacterMovement()->MaxWalkSpeed >= BaseWalkSpeed)
  {
   // Calculate the new walk speed and the delta speed
   float NewWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
   float DeltaSpeed = (BaseWalkSpeed * Multi - BaseWalkSpeed) / (SlideTime / GetWorld()->GetDeltaSeconds());

   // While the new walk speed is greater than or equal to the BaseWalkSpeed
   while (NewWalkSpeed >= BaseWalkSpeed)
   {
    // Decrease the new walk speed by the delta speed
    NewWalkSpeed -= DeltaSpeed;
    
    // Set the MaxWalkSpeed of the character's movement component to the new walk speed
    GetCharacterMovement()->MaxWalkSpeed = NewWalkSpeed;
   }

   // Set the MaxWalkSpeed of the character's movement component to the BaseWalkSpeed
   GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
  }
 }
}

// Method to check if the player has received any input
bool APlayerCharacter::InputReceived()
{
 // Get the value of the "MoveRight" axis
 float RightValue = InputComponent->GetAxisValue("MoveRight");

 // If the absolute value of the RightValue is greater than 0.1f, return true
 if(FMath::Abs(RightValue) > 0.1f)
 {
  return true;
 }

 // Otherwise, return false
 return false;
}

// Method to handle the event when the player overlaps with another object
void APlayerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
 // Check if the OtherActor and the OtherComp are not null and that the OtherActor is not the player
 if (OtherActor && (OtherActor != this) && OtherComp)
 {
  // If the OtherComp's collision response to the ECC_GameTraceChannel3 is either ECR_Block or ECR_Overlap
  if (OtherComp->GetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3) == ECollisionResponse::ECR_Block || OtherComp->GetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3) == ECollisionResponse::ECR_Overlap)
  {
   // Set bIsOverlappingWithMantle to true and log a message indicating that the player is overlapping with the OtherActor
   bIsOverlappingWithMantle = true;
   UE_LOG(LogTemp, Warning, TEXT("Overlapping with actor: %s"), *OtherActor->GetName());

   // Get the BoxComponent of the other actor

   if (UBoxComponent* OtherActorBoxComponent = Cast<UBoxComponent>(OtherActor->GetComponentByClass(UBoxComponent::StaticClass())))
   {
    // Get the location of the BoxComponent
    MantleLocation = OtherActorBoxComponent->GetComponentLocation();

    // Now BoxComponentLocation is a vector representing the location of the BoxComponent of the other actor
   }
   else
   {
    // Log a warning message if the OtherActor does not have a BoxComponent
    UE_LOG(LogTemp, Warning, TEXT("OtherActor does not have a BoxComponent."));
   }
  }
  else
  {
   UE_LOG(LogTemp, Warning, TEXT("OtherComp does not have a valid collision response."));
  }
 }else
 {
  UE_LOG(LogTemp, Warning, TEXT("OtherActor or OtherComp is null."));
 }
}
