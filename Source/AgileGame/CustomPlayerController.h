// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CustomMovementComponent.h"
#include "MovablePawn.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AGILEGAME_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:

	virtual void SetupInputComponent();
	virtual void CallForwards(float Value);
	virtual void CallTurn(float Value);
	
	AMovablePawn* MyPawn;
	
};
