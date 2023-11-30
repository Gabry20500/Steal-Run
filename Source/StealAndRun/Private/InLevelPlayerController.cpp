// Fill out your copyright notice in the Description page of Project Settings.


#include "InLevelPlayerController.h"

AInLevelPlayerController::AInLevelPlayerController()
{
}

void AInLevelPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &AInLevelPlayerController::MoveRight);
}

void AInLevelPlayerController::MoveRight(float AxisValue)
{
	
}
