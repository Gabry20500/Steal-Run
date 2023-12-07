// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "EditorUtilityWidget.h"
#include "MyEditorUtilityWidget.generated.h"

/**
 * 
 */
UCLASS()
class STEALANDRUN_API UMyEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnButtonClicked();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Modular Table")
	int32 TextBoxToInt(const class UEditableTextBox* TextBoxToConvert);
	
	UFUNCTION(BlueprintCallable, Category = "Modular Table")
	void ConstructTable(class UGridPanel* InGridPanel, int32 NumRows, int32 NumColumns);
};
