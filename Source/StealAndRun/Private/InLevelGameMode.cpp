// Fill out your copyright notice in the Description page of Project Settings.


#include "InLevelGameMode.h"
#include "PlayerCharacter.h"


AInLevelGameMode::AInLevelGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
}
