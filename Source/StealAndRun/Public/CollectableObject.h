// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ICollectable.h"
#include "CollectableObject.generated.h"

UCLASS()
class STEALANDRUN_API ACollectableObject : public AActor, public IICollectable
{
	GENERATED_BODY()
	
public:	
	ACollectableObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	int PointsEarned;
	
	UPROPERTY(EditAnywhere, Category = "Collectable")
	bool bIsPrimary = false;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Collectable")
	void Collect();

	int GetPoints();
};
