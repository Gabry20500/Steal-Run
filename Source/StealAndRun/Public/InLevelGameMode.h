// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidgetBlueprint.h"
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
	
	void SetPrimaryObjectObtained(bool bGetted) { bPrimaryObjectObtained = bGetted; }

	bool GetPrimaryObjectObtained() const { return bPrimaryObjectObtained; }
	
	void StartSecondPhase();

	UFUNCTION(BlueprintCallable, Category = "GamePhase")
	void ResetAtFirstPhase();

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	// UUserWidgetBlueprint* UIWidget;
	
protected:
	void Tick(float DeltaSeconds) override;
	
	bool bPrimaryObjectObtained = false;
};
