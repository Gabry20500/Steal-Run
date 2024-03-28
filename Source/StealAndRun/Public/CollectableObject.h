// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "./Interface/ICollectable.h"
#include "CollectableObject.generated.h"

UCLASS()
class STEALANDRUN_API ACollectableObject : public AActor, public IICollectable
{
	GENERATED_BODY()
	
public:	
	ACollectableObject();

	UPROPERTY(EditAnywhere, Category = "Collectable")
	int PointsEarned;
	
	UPROPERTY(EditAnywhere, Category = "Collectable")
	bool bIsPrimary = false;
	
	void Collect_Implementation() override; 

	int GetPoints_Implementation() override;
};
