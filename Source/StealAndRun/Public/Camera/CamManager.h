#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "CamManager.generated.h"

// Declaration of ACamManager class inheriting from APlayerCameraManager
UCLASS()
class STEALANDRUN_API ACamManager : public APawn
{
	GENERATED_BODY()
    
public:    
	// Constructor
	ACamManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:    
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to move the camera, exposed to Blueprint
	UFUNCTION(BlueprintCallable, Category="Camera")
	void MoveCamera(FVector NewLocation);

private:

	// Variables for camera movement
	FVector StartLocation;
	FVector TargetLocation;
	float LerpTime;
	float CurrentLerpTime;

	// Editable camera move time
	UPROPERTY(EditAnywhere, Category="Camera")
	float CamMoveTime;

	// Flag to check if the camera is moving
	bool bIsMoving;
};