// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
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
	float TimeToReset = 2.0f;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Interact_Implementation() override;

	void ResetPlatform();

};
