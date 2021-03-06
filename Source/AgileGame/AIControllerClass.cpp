// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerClass.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAIControllerClass::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); //Gets the player pawn 

	if (PlayerPosition != nullptr)
	{
		RunBehaviorTree(PlayerPosition);
	}

	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerPosition"), PlayerPawn->GetActorLocation()); //Sets the blackboard component called "PlayerPosition" and sets it as current players position
}

void AAIControllerClass::Tick(float DeltaTime)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); //Gets the player pawn 

	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerPosition"), PlayerPawn->GetActorLocation()); //Sets the blackboard component called "PlayerPosition" and sets it as current players position

	if (LineOfSightTo(PlayerPawn)) //Checks if the AI character has line of sight to the player pawn
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerPosition"), PlayerPawn->GetActorLocation()); //Sets the blackboard component called "PlayerPosition" and sets it as current players position
	}
	else
	{
		GetBlackboardComponent()->ClearValue(TEXT("PlayerPosition")); //Clears the current value of the player location 
	}


}