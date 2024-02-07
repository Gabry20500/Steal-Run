// Fill out your copyright notice in the Description page of Project Settings.


#include "InLevelGameMode.h"
#include "PlayerCharacter.h"


AInLevelGameMode::AInLevelGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
}

void AInLevelGameMode::StartSecondPhase()
{
	
}

void AInLevelGameMode::ResetAtFirstPhase()
{
}

//Protected function
void AInLevelGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(bPrimaryObjectObtained)
	{
		StartSecondPhase();
	}
}
