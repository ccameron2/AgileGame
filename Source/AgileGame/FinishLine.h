// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AgileGameGamemodeBase.h"
#include "Components/BoxComponent.h"	

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinishLine.generated.h"

UCLASS()
class AGILEGAME_API AFinishLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFinishLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* FinishLineMesh;
	
	UPROPERTY(EditAnywhere)
		UBoxComponent* FinishLineCollisionArea;

	UPROPERTY()
		AAgileGameGameModeBase* gamemodeRef;

	UPROPERTY(EditAnywhere)
		FName NextLevelName;

	UFUNCTION()
		void OnOverLapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
