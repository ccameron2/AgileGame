// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FinishLineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Finish Line Mesh"));
	FinishLineMesh->SetupAttachment(RootComponent);

	FinishLineCollisionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("OverLapCollision"));
	FinishLineCollisionArea->SetBoxExtent(FVector(270.0f, 250.0f, 0.0f));
	FinishLineCollisionArea->SetCollisionProfileName("RaceEndTrigger");
	FinishLineCollisionArea->SetupAttachment(FinishLineMesh);
}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	gamemodeRef = Cast<AAgileGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	FinishLineCollisionArea->OnComponentEndOverlap.AddDynamic(this, &AFinishLine::OnOverLapEnd);
}

// Called every frame
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFinishLine::OnOverLapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Passed Throught"));
	gamemodeRef->ChangeLevel();
}