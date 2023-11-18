// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class STEALANDRUN_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:

	/*FUNCTION*/
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "PlayerPawn")
	void OnShiftPressed();

	UFUNCTION(BlueprintCallable, Category = "PlayerPawn")
	void OnShiftReleased();
	
	/*VARIABLE*/
	UPROPERTY(EditAnywhere)
	class UBoxComponent* PlayerCollisionComponent;
	
	UPROPERTY(EditAnywhere)
	float BaseMoveForce = 1200.0f;

	UPROPERTY(EditAnywhere)
	float ShiftMultiplayer = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	float MoveForce;
	
	bool bIsShiftPressed = false;

protected:
	float TargetMoveForce;
	float InterpSpeed = 5.0f;

	float FasterInterpSpeed = 50.0f;

	virtual void Tick(float DeltaTime) override;
};
