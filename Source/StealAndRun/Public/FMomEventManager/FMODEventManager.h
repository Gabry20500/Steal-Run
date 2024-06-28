// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FMODAudioComponent.h"
#include "FMODEventManager.generated.h"

/**
 * 
 */
UCLASS()
class STEALANDRUN_API UFMODEventManager : public UObject
{
	GENERATED_BODY()

public:
	UFMODEventManager();

	UFUNCTION(BlueprintCallable, Category = "FMOD")
	void PlayFmodEvent(UObject* WorldContextObject, const FString& EventPath);

	UFUNCTION(BlueprintCallable, Category = "FMOD")
	void StopFmodEvent();

	UFUNCTION(BlueprintCallable, Category = "FMOD")
	void SetFmodParameter(FName ParameterName, float Value);

private:
	UFMODAudioComponent* FMODAudioComponet;
};
