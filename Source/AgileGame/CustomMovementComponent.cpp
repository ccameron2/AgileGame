// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"


void UCustomMovementComponent::MoveForward(float AxisX)
{
	FVector DeltaLocation = FVector(AxisX * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
	GetOwner()->AddActorLocalOffset(DeltaLocation, true);
}

void UCustomMovementComponent::Turn(float AxisZ)
{
	float RotateAmount = AxisZ * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0.0f, RotateAmount, 0.0f);
	FQuat DeltaRotation = FQuat(Rotation);
	GetOwner()->AddActorLocalRotation(DeltaRotation, true);
}


