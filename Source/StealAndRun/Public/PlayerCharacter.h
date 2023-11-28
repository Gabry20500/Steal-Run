// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class STEALANDRUN_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float Axisvalue);
	void StartJump();
	void StopJump();
	void StartRun();
	void StopRun();



private:
	
	bool bPressedJump;
	bool bisRunning;
	
	UPROPERTY(EditAnywhere, Category = "Player Movement")
	float multi;
};
