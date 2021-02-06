// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "Components/InputComponent.h"
#include "MovablePawn.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyPawn = Cast<AMovablePawn>(GetPawn());

}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);

	InputComponent->BindAxis("Drive", this, &ACustomPlayerController::CallForwards);
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::CallTurn);
}

void ACustomPlayerController::CallForwards(float Value)
{
	if (MyPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Forward"));
		MyPawn->PawnMovement->MoveForward(Value);
	}
}

void ACustomPlayerController::CallTurn(float Value)
{
	if (MyPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Turn"));
		MyPawn->PawnMovement->Turn(Value);
	}
}
