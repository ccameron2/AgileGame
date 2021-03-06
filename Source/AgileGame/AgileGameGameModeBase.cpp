// Copyright Epic Games, Inc. All Rights Reserved.


#include "AgileGameGameModeBase.h"

void AAgileGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	StartGame();
}
void AAgileGameGameModeBase::ChangeLevel()
{
	UE_LOG(LogTemp, Warning, TEXT("ChangeLevel"));
}
void AAgileGameGameModeBase::StartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("StartGame"));

}