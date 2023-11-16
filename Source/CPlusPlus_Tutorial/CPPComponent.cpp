// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/ArrowComponent.h"

// Sets default values
ACPPComponent::ACPPComponent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	UStaticMesh* mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/LevelPrototyping/Meshes/SM_Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(mesh);

	StaticMesh->SetupAttachment(RootComponent);

	UArrowComponent* Arrow;

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));

	Arrow->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();

	FString sMessage = "C++ HELLO F***ING WORLD";

	UKismetSystemLibrary::PrintString(
		this,
		sMessage,
		1,
		1,
		FColor::Cyan,
		5.f,
		TEXT("None"));
}

// Called every frame
void ACPPComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

