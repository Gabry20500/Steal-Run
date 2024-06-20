// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CamTrigger.generated.h"

UCLASS()
class STEALANDRUN_API ACamTrigger : public AActor
{
	GENERATED_BODY()

public:
	// Camera target position variables, editable in the Inspector
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera", meta = (ToolTip = "Adjust the distance of the camera from the player"))
	float CamX;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera", meta = (ToolTip = "Adjust the side position of the camera"))
	float CamY;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera", meta = (ToolTip = "Adjust the height of the camera"))
	float CamZ;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera", meta = (ToolTip = "Adjust the side DeadZone"))
	float CamYDeadZone;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera", meta = (ToolTip = "Adjust the height DeadZone"))
	float CamZDeadZone;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera", meta = (ToolTip = "Duration of the transition from PosA to PosB"))
	float LerpDuration;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	FVector OldStartPos;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	float OldZDeadZone;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	float OldYDeadZone;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	float OldFixedZ;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	float OldFixedY;
	
	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	bool TriggerUsed;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	bool IsInTrigger;

	UPROPERTY(Blueprintable,BlueprintReadWrite, Category="Camera")
	bool Forward;
};