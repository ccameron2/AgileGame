// Fill out your copyright notice in the Description page of Project Settings.


#include "MovablePawn.h"

// Sets default values
AMovablePawn::AMovablePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Car Mesh"));
	SetRootComponent(CarMesh);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(CarMesh);
	SpringArm->TargetArmLength = 700.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->SetRelativeRotation((new FRotator(-30, 0.0f, 0.0f))->Quaternion());
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(SpringArm);


}

// Called when the game starts or when spawned
void AMovablePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovablePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovablePawn::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Forward"));

	FVector DeltaLocation = FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
	GetOwner()->AddActorLocalOffset(DeltaLocation, true);
}

void AMovablePawn::Turn(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Turn"));

	float RotateAmount = Value * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator Rotation = FRotator(0.0f, RotateAmount, 0.0f);
	FQuat DeltaRotation = FQuat(Rotation);
	GetOwner()->AddActorLocalRotation(DeltaRotation, true);
}

