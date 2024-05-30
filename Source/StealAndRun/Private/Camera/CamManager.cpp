#include "Camera/CamManager.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

// Constructor
ACamManager::ACamManager()
{
    // Enable ticking every frame
    PrimaryActorTick.bCanEverTick = true;

    // Default move time, can be changed in the Inspector
    CamMoveTime = 2.0f;
    
    // Initialize moving flag
    bIsMoving = false;
}

// Called when the game starts or when spawned
void ACamManager::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ACamManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // If the camera is moving
    if (bIsMoving)
    {
        // Update lerp time
        CurrentLerpTime += DeltaTime;

        // Calculate lerp alpha
        float Alpha = CurrentLerpTime / LerpTime;

        // Check if lerp is complete
        if (Alpha >= 1.0f)
        {
            Alpha = 1.0f;
            bIsMoving = false;
        }

        // Calculate new camera location using linear interpolation
        FVector NewLocation = FMath::Lerp(StartLocation, TargetLocation, Alpha);

        SetActorLocation(NewLocation);
    }
}

// Move the camera to a new location
void ACamManager::MoveCamera(FVector NewLocation)
{
    // Initialize movement variables
        StartLocation = GetActorLocation();
        TargetLocation = NewLocation;
        LerpTime = CamMoveTime;
        CurrentLerpTime = 0.0f;
        bIsMoving = true;
}
