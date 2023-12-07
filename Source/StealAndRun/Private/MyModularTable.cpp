// Fill out your copyright notice in the Description page of Project Settings.


#include "MyModularTable.h"

#include "Components/GridPanel.h"
#include "Components/TextBlock.h"

void UMyModularTable::ConstructTable(UGridPanel* InGridPanel)
{
	if(InGridPanel)
	{
		for (int32 RowIndex = 0; RowIndex < NumRows; RowIndex++)
		{
			for (int32 ColumnIndex = 0; ColumnIndex < NumColumns; ColumnIndex++)
			{
				UTextBlock* NewTextBlock = NewObject<UTextBlock>(this);
				NewTextBlock->SetText(FText::FromString("Row: " + FString::FromInt(RowIndex) + ", Column: " + FString::FromInt(ColumnIndex)));
				InGridPanel->AddChildToGrid(NewTextBlock, RowIndex, ColumnIndex);
			}
		}
	}
}
