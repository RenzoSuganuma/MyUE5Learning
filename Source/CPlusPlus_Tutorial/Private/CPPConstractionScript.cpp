// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstractionScript.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPConstractionScript::ACPPConstractionScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	UStaticMesh* mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/LevelPrototyping/Meshes/SM_Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(mesh);

	StaticMesh->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	Arrow->SetRelativeLocation(FVector(30.f, 0.f, 0.f));

	Arrow->SetupAttachment(StaticMesh);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));

	PointLight->SetRelativeLocation(FVector(130.f, 0.f, 0.f));

	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPConstractionScript::BeginPlay()
{
	Super::BeginPlay();
	
	FString sMessage = "C++ HELLO WORLD";
	
	UKismetSystemLibrary::PrintString(
		this,
		sMessage,
		1,
		1,
		TextColor,
		fDuration,
		TEXT("None"));
}

// Called every frame
void ACPPConstractionScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPConstractionScript::OnConstruction(const FTransform& Transform)
{
	PointLight->SetVisibility(bIsVisible);

	PointLight->SetIntensity(fItensity);

	PointLight->SetLightColor(LightColor);
}