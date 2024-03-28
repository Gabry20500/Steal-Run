// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "IAbility.generated.h"

UINTERFACE(MinimalAPI)
class UIAbility : public UInterface
{
	GENERATED_BODY()
	
};

class STEALANDRUN_API IIAbility
{
	GENERATED_BODY()

public:
		
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void Use();
	virtual void Use_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void Stop();
	virtual void Stop_Implementation() = 0;
};