// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IAbility.h"
#include "HologramAbility.generated.h"

UCLASS()
class STEALANDRUN_API AHologramAbility : public AActor, public IIAbility
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHologramAbility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UWorld* CurrentWorld;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void UseAbility_Implementation() override;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	virtual void StopAbility_Implementation() override;
	
	void DrawMousePosition();
};
