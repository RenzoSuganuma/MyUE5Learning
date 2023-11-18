// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPEventDispatcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPPEventDispatcher::ACPPEventDispatcher()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnPrintHello.AddDynamic(this, &ACPPEventDispatcher::PrintHello);
}

void ACPPEventDispatcher::PrintHello()
{
	UKismetSystemLibrary::PrintString(
		this,
		"Hello!",
		1,
		1,
		FLinearColor::Blue,
		10.f,
		TEXT("None"));
}

int32 ACPPEventDispatcher::Sum(int32 a, int32 b)
{
	return a + b;
}

void ACPPEventDispatcher::PressedActionPrintString()
{
	UKismetSystemLibrary::PrintString(
		this,
		Message,
		1,
		1,
		FLinearColor::Blue,
		10.f,
		TEXT("None"));
}

// Called when the game starts or when spawned
void ACPPEventDispatcher::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();
}

void ACPPEventDispatcher::SetupInput()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPEventDispatcher::PressedH);
	InputComponent->BindAction("ActionPrintString", IE_Pressed, this, &ACPPEventDispatcher::PressedActionPrintString);
}

void ACPPEventDispatcher::PressedPopMessage()
{
}

void ACPPEventDispatcher::PressedH()
{
	/*UKismetSystemLibrary::PrintString(
		this,
		"H H H H H H",
		1,
		1,
		FLinearColor::Blue,
		10.f,
		TEXT("None"));*/
	OnPrintHello.Broadcast();
}

// Called every frame
void ACPPEventDispatcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}