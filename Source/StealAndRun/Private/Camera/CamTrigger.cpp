#include "Camera/CamTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CamManager.h"

void ACamTrigger::BeginPlay()
{
	Super::BeginPlay();

	// Find reference to the CamManager in the level
	CamManager = Cast<ACamManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ACamManager::StaticClass()));
	
	if (!CamManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("No CamManager found in the level."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cam trigger ok."));
	}
	
}

FVector ACamTrigger::GetCamPos()
{
	return FVector(CamX,CamY,CamZ);
}

