// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACPPCalculation::ACPPCalculation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();
	
	FString sMessage = "C++ Hello World";

	int32 iAddResult = UKismetMathLibrary::Add_IntInt(iValA, iValB);

	FString sResult = UKismetStringLibrary::Conv_IntToString(iAddResult);

	UKismetSystemLibrary::PrintString(
		this,
		sResult,
		1,
		1,
		TextColor,
		fDuration,
		TEXT("None"));
}

// Called every frame
void ACPPCalculation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

