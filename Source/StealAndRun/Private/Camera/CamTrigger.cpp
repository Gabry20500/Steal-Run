#include "Camera/CamTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CamManager.h"
#include "PlayerZDCharacter/PlayerZDCharacter.h"

// Called when the game starts or when spawned
void ACamTrigger::BeginPlay()
{
 Super::BeginPlay();

    // Find reference to the CamManager in the level
    CamManager = Cast<ACamManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ACamManager::StaticClass()));
    if (!CamManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("No CamManager found in the level."));
    }
}

// Function called when something enters the trigger box
void ACamTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APlayerZDCharacter* OtherPlayer = Cast<APlayerZDCharacter>(OtherActor);
	// Check if the overlapping actor is valid
	if (OtherPlayer && (OtherActor != this) && OtherComp)
	{
		// If CamManager is set
		if (CamManager)
		{
			// Create a new vector for the target camera position
			FVector NewCameraLocation(CamX, CamY, CamZ);
            
			// Move the camera to the new position
			CamManager->MoveCamera(NewCameraLocation);
		}
	}
}