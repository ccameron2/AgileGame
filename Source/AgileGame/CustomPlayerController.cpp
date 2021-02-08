// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "Components/InputComponent.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	VehiclePawn = Cast<AWheeledVehiclePawn>(GetPawn());
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent)
	InputComponent->BindAxis("Throttle", this, &ACustomPlayerController::CallApplyThrottle);
	InputComponent->BindAxis("Steer", this, &ACustomPlayerController::CallApplySteering);
	InputComponent->BindAxis("Look Up", this, &ACustomPlayerController::CallLookUp);
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::CallTurn);

	InputComponent->BindAction("Handbrake", IE_Pressed, this, &ACustomPlayerController::CallOnHandbrakePressed);
	InputComponent->BindAction("Handbrake", IE_Released, this, &ACustomPlayerController::CallOnHandbrakeReleased);
}

void ACustomPlayerController::CallApplyThrottle(float Value)
{
	if (VehiclePawn)
	{
		VehiclePawn->ApplyThrottle(Value);
	}
}

void ACustomPlayerController::CallApplySteering(float Value)
{
	if (VehiclePawn)
	{
		VehiclePawn->ApplySteering(Value);
	}
}

void ACustomPlayerController::CallLookUp(float Value)
{
	if (VehiclePawn)
	{
		VehiclePawn->LookUp(Value);
	}
}

void ACustomPlayerController::CallTurn(float Value)
{
	if (VehiclePawn)
	{
		VehiclePawn->Turn(Value);
	}
}

void ACustomPlayerController::CallOnHandbrakePressed()
{
	if (VehiclePawn)
	{
		VehiclePawn->OnHandbrakePressed();
	}
}

void ACustomPlayerController::CallOnHandbrakeReleased()
{
	if (VehiclePawn)
	{
		VehiclePawn->OnHandbrakeReleased();
	}
}

void ACustomPlayerController::CallUpdateInAirControl(float DeltaTime)
{
	if (VehiclePawn)
	{
		VehiclePawn->UpdateInAirControl(DeltaTime);
	}
}
