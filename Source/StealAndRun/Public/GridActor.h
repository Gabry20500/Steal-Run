// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GridActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STEALANDRUN_API UGridActor : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGridActor();

	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    FVector StartLocation;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    FVector GridSize;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
	int32 NumCellX;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
	int32 NumCellY;
	
	UFUNCTION(BlueprintCallable, Category = "Grid Settings")
    virtual void DrawGrid();
		
};
