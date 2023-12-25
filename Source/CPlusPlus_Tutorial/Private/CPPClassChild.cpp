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
	// Viewportに配置したActorの表示名を取得する
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名と関数名を出力
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s : CallChildFunc %d"), *name, VarChildNum), true, true, FColor::Blue, 10.f, TEXT("None"));
}
