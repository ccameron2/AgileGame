// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Components/StaticMeshComponent.h>
#include "GameFramework/SpringArmComponent.h"
#include <Camera/CameraComponent.h>

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "WheeledVehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class AGILEGAME_API AWheeledVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:
	AWheeledVehiclePawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void ApplyThrottle(float Value);
	void ApplySteering(float Value);

	void LookUp(float Value);
	void Turn(float Value);

	void OnHandbrakePressed();
	void OnHandbrakeReleased();

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
};
