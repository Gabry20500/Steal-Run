// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "IAbility.generated.h"

UINTERFACE(MinimalAPI)
class UIAbility : public UInterface
{
	GENERATED_BODY()

};

class STEALANDRUN_API IIAbility
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void UseAbility();
	virtual void UseAbility_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void StopAbility();
	virtual void StopAbility_Implementation() = 0;
	
	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityTick(float DeltaTime);
	virtual void AbilityTick_Implementation(float DeltaTime) = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityEnd();
	virtual void AbilityEnd_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityStart();
	virtual void AbilityStart_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityCooldown();
	virtual void AbilityCooldown_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityReady();
	virtual void AbilityReady_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityInterrupted();
	virtual void AbilityInterrupted_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityFailed();
	virtual void AbilityFailed_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilitySucceeded();
	virtual void AbilitySucceeded_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityReset();
	virtual void AbilityReset_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityCharged();
	virtual void AbilityCharged_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityCharging();
	virtual void AbilityCharging_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityCharge();
	virtual void AbilityCharge_Implementation() = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityChargeTick(float DeltaTime);
	virtual void AbilityChargeTick_Implementation(float DeltaTime) = 0;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	void AbilityChargeEnd();
	virtual void AbilityChargeEnd_Implementation() = 0;*/
};
