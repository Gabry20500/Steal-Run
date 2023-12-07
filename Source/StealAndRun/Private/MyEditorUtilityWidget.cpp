// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEditorUtilityWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/GridPanel.h"

void UMyEditorUtilityWidget::OnButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked!"));
}

int32 UMyEditorUtilityWidget::TextBoxToInt(const UEditableTextBox* TextBoxToConvert)
{
	if (TextBoxToConvert)
	{
		FString TextString = TextBoxToConvert->GetText().ToString();
		int32 ConvertedInt = FCString::Atoi(*TextString);
		return ConvertedInt;
	}
    
	// Default return value if TextBoxToConvert is null or other issues occur
	return 0;
}


void UMyEditorUtilityWidget::ConstructTable(UGridPanel* InGridPanel, int32 NumRows, int32 NumColumns)
{
	if(InGridPanel)
	{
		InGridPanel->ClearChildren();

		for (int32 RowIndex = 0; RowIndex < NumRows; RowIndex++)
		{
			for (int32 ColumnIndex = 0; ColumnIndex < NumColumns; ColumnIndex++)
			{
				UButton* NewButton = NewObject<UButton>(this);
				NewButton->OnClicked.AddDynamic(this, &UMyEditorUtilityWidget::OnButtonClicked);
                
				// Customize the button appearance or behavior here if needed

				InGridPanel->AddChildToGrid(NewButton, RowIndex, ColumnIndex);
			}
		}
	}
}
