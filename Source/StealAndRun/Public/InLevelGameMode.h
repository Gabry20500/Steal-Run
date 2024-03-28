// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InLevelGameMode.generated.h"

/**
 * 
 */
UCLASS()
class STEALANDRUN_API AInLevelGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInLevelGameMode();

	UFUNCTION(BlueprintCallable, Category = "GamePhase")
	void SetPrimaryObjectObtained(bool bGetted) { bPrimaryObjectObtained = bGetted; }

	UFUNCTION(BlueprintCallable, Category = "GamePhase")
	bool GetPrimaryObjectObtained() const { return bPrimaryObjectObtained; }

protected:
	bool bPrimaryObjectObtained = false;

	void Tick(float DeltaSeconds) override;
};
