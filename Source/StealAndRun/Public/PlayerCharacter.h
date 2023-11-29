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

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

private:
	
	void MoveRight(float Axisvalue);
	void StartJump();
	void StopJump();
	void StartRun();
	void StopRun();
	void StartSlide();
	void StopSlide();
	bool InputReceived();

	//Run Variables
	float BaseWalkSpeed;
	bool bisRunning;
	float Multi;

	//Jump Variables
	bool bPressedJump;

	
	bool bIsSliding;
	float SlideTime;
	float SlideSpeedMultiplier;
	float SlideDuration;

	FTimerHandle SlideTimerHandle;
	

};
