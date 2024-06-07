// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CamManager.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "CamTrigger.generated.h"

UCLASS()
class STEALANDRUN_API ACamTrigger : public AActor
{
	GENERATED_BODY()

public:
	// Camera target position variables, editable in the Inspector
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	float CamX;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	float CamY;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	float CamZ;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	float CamZDeadZone;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	float CamYDeadZone;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	bool TriggerUsed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Camera")
	bool IsInTrigger;
};