// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CustomMovementComponent.h"

#include <Components/StaticMeshComponent.h>
#include "GameFramework/SpringArmComponent.h"
#include <Camera/CameraComponent.h>

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MovablePawn.generated.h"

UCLASS()
class AGILEGAME_API AMovablePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovablePawn();

public:	

	// Called to bind functionality to input
	//UFUNCTION()
	//	void MoveForward(float Value);

	//UFUNCTION()
	//	void Turn(float Value);

	UPROPERTY(EditAnywhere)
		UCustomMovementComponent* PawnMovement;

private:

	UPROPERTY(EditAnywhere)
		float MoveSpeed = 500.0f;

	UPROPERTY(EditAnywhere)
		float RotationSpeed = 50.0f;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CarMesh;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;


};
