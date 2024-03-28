// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "IInteractable.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class UIInteractable : public UInterface
{
	GENERATED_BODY()
	
};

class STEALANDRUN_API IIInteractable
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();
	virtual void Interact_Implementation() = 0;
};