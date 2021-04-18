// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AgileGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class AGILEGAME_API AAgileGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	UFUNCTION()
		void ChangeLevel();
	UFUNCTION()
		void LapPassed();

	UPROPERTY(EditAnywhere)
		int laps;

	UPROPERTY(EditAnywhere)
		int maxLaps = 2;

	UPROPERTY(EditAnywhere)
		FName nextLevelName;
private:
	UFUNCTION()
		void StartGame();
};
