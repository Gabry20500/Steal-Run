// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInteractable.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
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

	//Interact Function and Variables
	UFUNCTION(BlueprintCallable)
	void OpenDoor(UBoxComponent* HitBoxComponent);
	
	UPROPERTY(BlueprintReadWrite, Category = "Interactable")
	bool bIsInteracting = false;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	
private:
	
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
	

	//Interact Variable
	AActor* ObjInteractable;
	IIInteractable* ObjInteractableInterface;

	
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void GetInteractableObject(AActor* Actor);
	
	//Run Variables
	float BaseWalkSpeed;
	bool bisRunning;
	float Multi;
	float SlideTime;

	void StartRun();
	void StopRun();
	bool InputReceived();

	void MoveRight(float Axisvalue);

	void Interact();
};
