// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

float FPIDController::CalcNewInput(float Error, float Position)
{
	ErrorSum = FMath::Clamp(Error + ErrorSum, ErrorMin, ErrorMax);
	float Input = Error * Proportional + ErrorSum * Integral + Derivative * (LastPosition - Position);
	LastPosition = Position;
	return Input;
}

void UAIMovementComponent::RequestDirectMove(const FVector& MoveVecocity, bool bForceMaxSpeed)
{
	Super::RequestDirectMove(MoveVecocity, bForceMaxSpeed);
	FVector VehicleLocation = GetOwner()->GetActorLocation();
	FVector Destination = VehicleLocation + MoveVecocity * GetWorld()->GetDeltaSeconds();


	FVector Distance = Destination - VehicleLocation;
	FVector InitialDistance = Destination - InitialLocation;
	FVector VehicleDirection = GetOwner()->GetActorForwardVector();

	// Throttle controller
	float ForwardFactor = FVector::DotProduct(VehicleDirection, Distance.GetSafeNormal());

	float Error = Distance.Size() / InitialDistance.Size() * FMath::Sign(ForwardFactor);
	float Position = 1 - Error;

	float Input = ThrottleController.CalcNewInput(Error, Position);

	const float TURN_AROUND_FACTOR = bTurningAround ? 0.3f : 0.1f;
	if (ForwardFactor < TURN_AROUND_FACTOR && (bForceMaxSpeed || Distance.Size() > 300.f))
	{
		bTurningAround = true;
		SetThrottleInput(-1.f);
	}
	else
	{
		bTurningAround = false;
		SetThrottleInput(bForceMaxSpeed ? ForwardFactor : Input);
	}

	// Steering controller
	float InitialYaw = InitialDistance.Rotation().Yaw - InitialDirection.Rotation().Yaw;
	if (InitialYaw < -180)
	{
		InitialYaw += 360;
	}
	else if (InitialYaw > 180)
	{
		InitialYaw -= 360;
	}
	float CurrentYaw = Distance.Rotation().Yaw - VehicleDirection.Rotation().Yaw;
	if (CurrentYaw < -180)
	{
		CurrentYaw += 360;
	}
	else if (CurrentYaw > 180)
	{
		CurrentYaw -= 360;
	}

	float SteeringPosition = (-CurrentYaw + 180) / 180;
	float SteeringError = 1 - SteeringPosition;

	float SteeringInputDeclaration = SteeringControllerS.CalcNewInput(SteeringError, SteeringPosition);
	if (bTurningAround)
	{
		SetSteeringInput(SteeringError > 0 ? -1.f : 1.f);
	}
	else
	{
		SetSteeringInput(SteeringInputDeclaration);
	}
	SetHandbrakeInput(false);
}

void UAIMovementComponent::StopActiveMovement()
{
	Super::StopActiveMovement();
	InitialLocation = GetOwner()->GetActorLocation();
	InitialDirection = GetOwner()->GetActorForwardVector();
	SetHandbrakeInput(true);
	SetThrottleInput(0.f);
}