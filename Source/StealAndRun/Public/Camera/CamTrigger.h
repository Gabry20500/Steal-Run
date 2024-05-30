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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Camera target position variables, editable in the Inspector
	UPROPERTY(EditAnywhere, Category="Camera")
	float CamX;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CamY;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CamZ;

	UPROPERTY(BlueprintReadWrite, Category="Camera")
	ACamManager* CamManager;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Camera")
	FVector GetCamPos();
};