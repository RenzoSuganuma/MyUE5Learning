// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCPPClassChild.h"
#include "Kismet/KismetSystemLibrary.h"

AMyCPPClassChild::AMyCPPClassChild()
{
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Content/StarterContent/Shapes/Shape_Sphere"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);

	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("/Game/Content/StarterContent/Materials/M_Brick_Cut_Stone"), NULL, LOAD_None, NULL);
	StaticMesh->SetMaterial(0, Material);
}

void AMyCPPClassChild::BeginPlay()
{
	Super::BeginPlay();

	CallChildFunc();
}

void AMyCPPClassChild::CallChildFunc()
{
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallChildFunc %d"), *name, VarChildNum), true, true, FColor::Blue, 10.f, TEXT("None"));
}
