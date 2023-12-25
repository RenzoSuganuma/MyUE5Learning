// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPClassBase.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPClassBase::ACPPClassBase()
{
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cone"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACPPClassBase::BeginPlay()
{
	Super::BeginPlay();
	
	CallParentFunc();
}

void ACPPClassBase::CallParentFunc() 
{
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallParentFunc %d"), *name, VarParentNum), true, true, FColor::Cyan, 10.f, TEXT("None"));
}

