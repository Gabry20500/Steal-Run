// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CamManager.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "CamTrigger.generated.h"

UCLASS()
class STEALANDRUN_API ACamTrigger : public AActor
{
	GENERATED_BODY()

public:    

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Camera target position variables, editable in the Inspector
	UPROPERTY(EditAnywhere, Category="Camera")
	float CamX;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CamY;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CamZ;
	
	

private:
	// Function called when something enters the trigger box
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	// Trigger box component
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerBox;
	ACamManager* CamManager;
};