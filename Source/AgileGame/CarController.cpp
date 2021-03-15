// Fill out your copyright notice in the Description page of Project Settings.
#include "CarController.h"
#include "Kismet\GameplayStatics.h"

void ACarController::BeginPlay()
{
	Super::BeginPlay();

	MyPawn = Cast<AWheeledVehiclePawn>(GetPawn());
}

void ACarController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
	InputComponent->BindAxis("Steer", this, &ACarController::CallApplySteering);
	InputComponent->BindAxis("Look Up", this, &ACarController::CallLookUp);
	InputComponent->BindAxis("Throttle", this, &ACarController::CallForward);
	InputComponent->BindAxis("Turn", this, &ACarController::CallTurn);

	InputComponent->BindAction("Handbrake", IE_Pressed, this, &ACarController::CallOnHandbrakePressed);
	InputComponent->BindAction("Handbrake", IE_Released, this, &ACarController::CallOnHandbrakeReleased);
}

void ACarController::CallForward(float Value)
{
	if (MyPawn)
	{
		MyPawn->ApplyThrottle(Value);	
	}
}

void ACarController::CallTurn(float Value)
{
	if (MyPawn)
	{
		MyPawn->Turn(Value);
	}
}


void ACarController::CallApplySteering(float Value)
{
	if (MyPawn)
	{
		MyPawn->ApplySteering(Value);
	}
}


void ACarController::CallLookUp(float Value)
{
	if (MyPawn)
	{
		MyPawn->LookUp(Value);
	}
}

void ACarController::CallOnHandbrakePressed()
{
	if (MyPawn)
	{
		MyPawn->OnHandbrakePressed();
	}
}

void ACarController::CallOnHandbrakeReleased()
{
	if (MyPawn)
	{
		MyPawn->OnHandbrakeReleased();
	}
}
