// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "CustomMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class AGILEGAME_API UCustomMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void MoveForward(float AxisValue);

	void Turn(float AxisValue);

private:
	UPROPERTY(EditAnywhere)
		float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
		float RotationSpeed = 500.0f;
};