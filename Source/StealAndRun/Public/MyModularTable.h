// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyModularTable.generated.h"

/**
 * 
 */

UCLASS(Blueprintable, BlueprintType)
class STEALANDRUN_API UMyModularTable : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, Category = "Modular Table")
	int32 NumRows = 5;

	UPROPERTY(EditAnywhere, Category = "Modular Table")
	int32 NumColumns = 10;

	UFUNCTION(BlueprintCallable, Category = "Modular Table")
	void ConstructTable(UGridPanel* InGridPanel);
};
