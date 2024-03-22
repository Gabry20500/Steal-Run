// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "PlayerCharacter.h"
#include "InteractablePlatform.generated.h"

UCLASS()
class STEALANDRUN_API AInteractablePlatform : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractablePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* MeshComponent;

	FTimerHandle TimerHandle;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interactable")
	float TimeToGoUp = 0.3f;
	float TimeToReset = 2.0f;

	FVector PlayerVelocity;
	APlayerCharacter* Player;
	bool isInFalling;
	
	
public:	

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	bool GetIsInFalling() { return isInFalling; }
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Interact_Implementation() override;

	void ResetPlatform();

	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Interactable")
	void SetPlayerVelocity(FVector PlayerVel, APlayerCharacter* PlayerRef);
};
