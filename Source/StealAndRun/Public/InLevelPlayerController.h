// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InLevelPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STEALANDRUN_API AInLevelPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AInLevelPlayerController();

	virtual void SetupInputComponent() override;

	void MoveRight(float AxisValue);
};
