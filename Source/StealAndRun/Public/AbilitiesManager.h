// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitiesManager.generated.h"

UENUM()
enum AbilityEnum
{
	None,
	Hologram,
	Hacking
};

UCLASS()
class STEALANDRUN_API AAbilitiesManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilitiesManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	TArray<class IIAbility*> Abilities;
	
	IIAbility* CurrentAbility;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SetAbility(AbilityEnum AbilityType);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void UseAbility();

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void StopAbility();

};
