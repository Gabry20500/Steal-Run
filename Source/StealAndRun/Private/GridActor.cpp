// Fill out your copyright notice in the Description page of Project Settings.
#include "GridActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UGridActor::UGridActor()
{
	PrimaryComponentTick.bCanEverTick = true;

	StartLocation = FVector(0.0f, 0.0f, 0.0f);
	GridSize = FVector(100.0f, 100.0f, 0.0f);
	NumCellX = 10;
	NumCellY = 10;
}

void UGridActor::DrawGrid()
{
	UStaticMeshComponent* GridMeshComponent = NewObject<UStaticMeshComponent>(this);
	if(GridMeshComponent)
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> GridMesh(TEXT("/Game/GameDesignTool/GridMesh/Griglia_quad.Griglia_quad"));
		if (GridMesh.Succeeded())
		{
			GridMeshComponent->SetStaticMesh(GridMesh.Object);
			GridMeshComponent->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);

			FVector CellSize = FVector(100.0f, 100.0f, 0.0f);

			for (int32 i = 0; i < NumCellX; i++)
			{
				for (int32 j = 0; j < NumCellY; j++)
				{
					FVector CellLocation = StartLocation + FVector(i * CellSize.X, j * CellSize.Y, 0.0f);
					FTransform CellTransform(CellLocation);
					UStaticMeshComponent* NewCell = DuplicateObject(GridMeshComponent, this);
					if (NewCell)
					{
						NewCell->SetWorldTransform(CellTransform);
						//NewCell->RegisterComponent();
					}
				}
			}
		}
	}
}



