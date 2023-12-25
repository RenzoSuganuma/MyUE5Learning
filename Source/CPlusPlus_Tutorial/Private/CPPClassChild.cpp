// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPClassChild.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPClassChild::ACPPClassChild()
{
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Sphere"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);
}

void ACPPClassChild::BeginPlay()
{
	Super::BeginPlay();

	CallChildFunc();
}

void ACPPClassChild::CallChildFunc()
{
	// Viewport�ɔz�u����Actor�̕\�������擾����
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintString��Actor�\�����Ɗ֐������o��
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallChildFunc %d"), *name, VarChildNum), true, true, FColor::Blue, 10.f, TEXT("None"));
}
