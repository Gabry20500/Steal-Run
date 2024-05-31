// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AbilitiesManager.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

#include "PlayerZDCharacter.generated.h"

class USphereComponent;
// Enum for player direction
UENUM(BlueprintType)
enum class EnPlayerDirection : uint8
{
	None,
	Left,
	Right
};

/**
 * 
 */
UCLASS()
class STEALANDRUN_API APlayerZDCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:

	APlayerZDCharacter();

// Override the SetupPlayerInputComponent method
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Interactable and Collectable properties
	UPROPERTY(BlueprintReadWrite, Category = "Interactable")
	bool bIsInteracting = false;

	UPROPERTY(BlueprintReadWrite, Category = "Interactable")
	bool bUsePlatform = false;
	
	UPROPERTY(BlueprintReadWrite, Category = "Collectable")
	bool bIsCollectable = false;
	
	AAbilitiesManager* CurrentAbilitiesManager;
	
	// Score property
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectable")
	int Score = 0;
	
	// Mantle property
	UPROPERTY(EditAnywhere ,BlueprintReadWrite, Category = "Mantle")
	bool bIsOverlappingWithMantle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Run")
	bool bisRunning;
	
	// Method to open a door
	UFUNCTION(BlueprintCallable)
	void OpenDoor(UBoxComponent* HitBoxComponent);

	// Getters and Setters
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void SetbIsInteracting(bool value) { bIsInteracting = value; }

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void SetbUsePlatform(bool value) { bUsePlatform = value; }
	
	UFUNCTION(BlueprintCallable, Category = "Collectable")
	void SetbIsCollectable(bool value) { bIsCollectable = value; }

	UFUNCTION(BlueprintCallable, Category = "AbilitiesManager")
	void SetCurrentAbility(AAbilitiesManager *AbilitiesManager) { CurrentAbilitiesManager = AbilitiesManager; }
	
	// Method to get the score as a string
	UFUNCTION(BlueprintPure, Category = "Collectable")
	int GetScore(){ return  Score; }
	
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
	UPaperZDAnimationComponent* AnimationComponent;

	// Player direction property
	EnPlayerDirection PlayerDirection = EnPlayerDirection::None;
	
	// Interact Variable
	AActor* ObjCollectable;

	// Methods to get the interactable and collectable objects
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void SetInteractableObject(AActor* Actor)
	{
		ObjInteractable = Actor;

		UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjInteractable->GetName());
	}

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void SetCollectableObject(AActor* Actor) { ObjCollectable = Actor; }
	
	// Run Variables
	float BaseWalkSpeed;

	float Multi;
	float SlideTime;

	// Methods to start and stop running
	void StartRun();
	void StopRun();

	// Method to check if the player has received any input
	bool InputReceived() const;

	// Method to handle the event when the player overlaps with another object
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Method to move the player to the right
	void MoveRight(float Axisvalue);

	void MoveDown();

	// Method to handle the player's interaction with objects
	void Interact();

	// Method to handle the player's collection of objects
	void UseAbility();
	
	// Mantle location property
	FVector MantleLocation;

};
