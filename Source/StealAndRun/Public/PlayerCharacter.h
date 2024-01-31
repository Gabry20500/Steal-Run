// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UENUM(BlueprintType)
enum class EPlayerDirection : uint8
{
	None,
	Left,
	Right
};



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

	//Jump Variables
	void OnJumpStart();
	void OnJumpEnd();

	EPlayerDirection PlayerDirection = EPlayerDirection::None;
	
	UPROPERTY(EditAnywhere, Category = "Jump")
	float JumpZVelocity = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Jump")
	float MaxJumpDuration = .5f;

	bool bIsJumping = false;
	float JumpStartTime = 0.0f;
	

	//Run Variables
	float BaseWalkSpeed;
	bool bisRunning;
	float Multi;
	float SlideTime;

	void StartRun();
	void StopRun();
	bool InputReceived();
};
