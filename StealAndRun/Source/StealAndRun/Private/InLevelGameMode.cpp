// Fill out your copyright notice in the Description page of Project Settings.


#include "InLevelGameMode.h"
#include "PlayerPawn.h"
#include "InLevelPlayerController.h"


AInLevelGameMode::AInLevelGameMode()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	PlayerControllerClass = AInLevelPlayerController::StaticClass();
}
