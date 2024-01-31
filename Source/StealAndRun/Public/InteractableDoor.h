// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "InteractableDoor.generated.h"

UCLASS()
class STEALANDRUN_API AInteractableDoor : public AActor, public IIInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactable")
	bool bIsPlayerNear = false;
	
	void SetPlayerNear(bool bIsNear) { bIsPlayerNear = bIsNear; }
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();

};
