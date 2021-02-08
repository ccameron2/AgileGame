// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WheeledVehiclePawn.h"

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

	void CallApplyThrottle(float Value);
	void CallApplySteering(float Value);
		 
	void CallLookUp(float Value);
	void CallTurn(float Value);
		 
	void CallOnHandbrakePressed();
	void CallOnHandbrakeReleased();
		 
	void CallUpdateInAirControl(float DeltaTime);

	AWheeledVehiclePawn* VehiclePawn;
};
