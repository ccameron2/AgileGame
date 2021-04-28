// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WheeledVehiclePawn.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CarController.generated.h"

/**
 * 
 */
UCLASS()
class AGILEGAME_API ACarController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	void SetupInputComponent();
	
	UPROPERTY()
		class AWheeledVehiclePawn* MyPawn;


private:
	//virtual void CallForward(float AxisValue);
	virtual void CallTurn(float AxisValue);
	//virtual void CallApplySteering(float Value);
	virtual void CallLookUp(float Value);
	//virtual void CallOnHandbrakePressed();
	//virtual void CallOnHandbrakeReleased();

};
