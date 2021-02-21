// Fill out your copyright notice in the Description page of Project Settings.


#include "WheeledVehiclePawn.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"

AWheeledVehiclePawn::AWheeledVehiclePawn()
{
	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());

	Vehicle4W->MinNormalizedTireLoad = 0.0f;
	Vehicle4W->MinNormalizedTireLoadFiltered = 0.2f;
	Vehicle4W->MaxNormalizedTireLoad = 2.0f;
	Vehicle4W->MaxNormalizedTireLoadFiltered = 2.0f;

	Vehicle4W->MaxEngineRPM = 5700.0f;
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f,400.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(1890.0f,500.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(5730.0f,400.0f);

	Vehicle4W->SteeringCurve.GetRichCurve()->Reset();
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(0.0f, 1.0f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(40.0f, 0.7f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(120.0f, 0.6f);

	Vehicle4W->DifferentialSetup.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;
	Vehicle4W->DifferentialSetup.FrontRearSplit = 0.65;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->FieldOfView = 90.0f;

}

void AWheeledVehiclePawn::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}

void AWheeledVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(InputComponent)
	
}

void AWheeledVehiclePawn::ApplyThrottle(float Value)
{
	UWheeledVehicleMovementComponent* VehicleMovementComponent = GetVehicleMovementComponent();
	VehicleMovementComponent->SetThrottleInput(Value);

	//UE_LOG(LogTemp, Warning, TEXT("Throttle"));
}

void AWheeledVehiclePawn::ApplySteering(float Value)
{
	UWheeledVehicleMovementComponent* VehicleMovementComponent = GetVehicleMovementComponent();
	VehicleMovementComponent->SetSteeringInput(Value);

	//UE_LOG(LogTemp, Warning, TEXT("Steer"));
}

void AWheeledVehiclePawn::LookUp(float Value)
{
	if (Value != 0)
	{
		AddControllerPitchInput(Value);
		//UE_LOG(LogTemp, Warning, TEXT("LookUp"));
	}
}

void AWheeledVehiclePawn::Turn(float Value)
{
	if (Value != 0)
	{
		AddControllerYawInput(Value);
		//UE_LOG(LogTemp, Warning, TEXT("Turn"));
	}
}

void AWheeledVehiclePawn::OnHandbrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);

}

void AWheeledVehiclePawn::OnHandbrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

