// Fill out your copyright notice in the Description page of Project Settings.


#include "FMomEventManager/FMODEventManager.h"

#include "FMODBlueprintStatics.h"

UFMODEventManager::UFMODEventManager()
{
	FMODAudioComponet = CreateDefaultSubobject<UFMODAudioComponent>(TEXT("FMODAudioComponent"));
}

void UFMODEventManager::PlayFMODSound(const FString& SoundPath)
{
	
}

void UFMODEventManager::StopFmodEvent()
{
	if(FMODAudioComponet)
	{
		FMODAudioComponet->Stop();
	}
}

void UFMODEventManager::SetFmodParameter(FName ParameterName, float Value)
{
	if(FMODAudioComponet)
	{
		FMODAudioComponet->SetParameter(ParameterName, Value);
	}
}
