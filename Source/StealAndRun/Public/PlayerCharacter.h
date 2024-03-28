// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableObject.h"
#include "./Interface/IInteractable.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "PlayerCharacter.generated.h"

// Enum for player direction
UENUM(BlueprintType)
enum class EPlayerDirection : uint8
{
	None,
	Left,
	Right
};


// PlayerCharacter class declaration
UCLASS()
class STEALANDRUN_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Override the SetupPlayerInputComponent method
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Interactable and Collectable properties
	UPROPERTY(BlueprintReadWrite, Category = "Interactable")
	bool bIsInteracting = false;
	
	UPROPERTY(BlueprintReadWrite, Category = "Collectable")
	bool bIsCollectable = false;

	// Score property
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int Score = 0;
	
	// Mantle property
	UPROPERTY(EditAnywhere ,BlueprintReadWrite, Category = "Mantle")
	bool bIsOverlappingWithMantle;
	
	// Method to open a door
	UFUNCTION(BlueprintCallable)
	void OpenDoor(UBoxComponent* HitBoxComponent);

	// Getters and Setters
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void SetbIsInteracting(bool value) { bIsInteracting = value; }
	
	UFUNCTION(BlueprintCallable, Category = "Collectable")
	void SetbIsCollectable(bool value) { bIsCollectable = value; }

	// Method to get the score as a string
	UFUNCTION(BlueprintPure, Category = "Collectable")
	FString GetScoreString(){ return  FString::Printf(TEXT("%d"), Score); }

	// Method to get the mantle location
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Mantle")
	FVector GetMantleLocation() { return MantleLocation; }
	
	// Interactable object property
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectable")
	AActor* ObjInteractable;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Player Components
	USphereComponent* PlySphereComponent;

	// Player direction property
	EPlayerDirection PlayerDirection = EPlayerDirection::None;
	
	// Jump properties
	bool bIsJumping = false;
	float JumpStartTime = 0.0f;
	
	// Interact Variable
	AActor* ObjCollectable;

	// Methods to get the interactable and collectable objects
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void GetInteractableObject(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void GetCollectableObject(AActor* Actor);
	
	// Run Variables
	float BaseWalkSpeed;

	UPROPERTY(EditAnywhere, Category = "Run")
	bool bisRunning;
	float Multi;
	float SlideTime;

	// Methods to start and stop running
	void StartRun();
	void StopRun();

	// Method to check if the player has received any input
	bool InputReceived();

	// Method to handle the event when the player overlaps with another object
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Method to move the player to the right
	void MoveRight(float Axisvalue);

	// Method to handle the player's interaction with objects
	void Interact();

	// Mantle location property
	FVector MantleLocation;
};