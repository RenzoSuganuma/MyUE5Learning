// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructor.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPConstructor::ACPPConstructor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	hp = 100;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/LevelPrototyping/Meshes/SM_Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACPPConstructor::BeginPlay()
{
	Super::BeginPlay();
	
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%d"), hp), 1, 1, FColor::Cyan, 2.f, TEXT("None"));
}

void ACPPConstructor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UKismetSystemLibrary::PrintString(this, TEXT("EndPlay Class Destroyed"), 1, 1, FColor::Cyan, 2.f);
}
