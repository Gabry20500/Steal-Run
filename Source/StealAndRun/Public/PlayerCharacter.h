// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableObject.h"
#include "IInteractable.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
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
	
	
	UPROPERTY(BlueprintReadWrite, Category = "Interactable")
	bool bIsInteracting = false;
	
	UPROPERTY(BlueprintReadWrite, Category = "Collectable")
	bool bIsCollectable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectable")
	int Score = 0;
	
	UPROPERTY(EditAnywhere ,BlueprintReadWrite, Category = "Mantle")
	bool bIsOverlappingWithMantle;
	
	


	UFUNCTION(BlueprintCallable)
	void OpenDoor(UBoxComponent* HitBoxComponent);

	//Getters and Setters
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void SetbIsInteracting(bool value) { bIsInteracting = value; }
	
	UFUNCTION(BlueprintCallable, Category = "Collectable")
	void SetbIsCollectable(bool value) { bIsCollectable = value; }

	UFUNCTION(BlueprintPure, Category = "Collectable")
	FString GetScoreString(){ return  FString::Printf(TEXT("%d"), Score); }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Mantle")
	FVector GetMantleLocation() { return MantleLocation; }
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectable")
	AActor* ObjInteractable;
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	
private:
	//Player Components
	USphereComponent* PlySphereComponent;
	
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
	AActor* ObjCollectable;

	
	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void GetInteractableObject(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void GetCollectableObject(AActor* Actor);
	
	//Run Variables
	float BaseWalkSpeed;
	bool bisRunning;
	float Multi;
	float SlideTime;

	void StartRun();
	void StopRun();
	bool InputReceived();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void MoveRight(float Axisvalue);

	void Interact();

	FVector MantleLocation;
};
