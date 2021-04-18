// Copyright Epic Games, Inc. All Rights Reserved.

#include "AgileGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AAgileGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}
void AAgileGameGameModeBase::ChangeLevel()
{
	UE_LOG(LogTemp, Warning, TEXT("ChangeLevel"));
	UGameplayStatics::OpenLevel(GetWorld(), nextLevelName);
}
void AAgileGameGameModeBase::LapPassed()
{
	laps++;
	if (laps >= maxLaps)
	{
		ChangeLevel();
	}
}
void AAgileGameGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("StartGame"));
	laps = 0;
}