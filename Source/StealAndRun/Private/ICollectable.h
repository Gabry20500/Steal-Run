// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "ICollectable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UICollectable : public UInterface
{
	GENERATED_BODY()
	
};

class STEALANDRUN_API IICollectable
{
	GENERATED_BODY()

public:

	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Collectable")
	int GetPoints();
	virtual int GetPoints_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Collectable")
	void Collect();
	virtual void Collect_Implementation() = 0;
	
};