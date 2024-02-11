// Fill out your copyright notice in the Description page of Project Settings.


#include "PoopHoge.h"
#include "Kismet\KismetSystemLibrary.h"

// Sets default values
APoopHoge::APoopHoge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APoopHoge::SayHoge()
{
	UKismetSystemLibrary::PrintString(this, TEXT("Hoge Hoge UE5"), true, true, FColor::Emerald, 1.f, "NONE");
}

// Called when the game starts or when spawned
void APoopHoge::BeginPlay()
{
	// Super::BeginPlay();
	SayHoge();
}

// Called every frame
void APoopHoge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

