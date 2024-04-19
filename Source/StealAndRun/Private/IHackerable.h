// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "IHackerable.generated.h"


UINTERFACE(MinimalAPI)
class UIHackerable : public UInterface
{
	GENERATED_BODY()
};

class STEALANDRUN_API IIHackerable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Disabling")
	void Disable();
	virtual void Disable_Implementation() = 0;
};
