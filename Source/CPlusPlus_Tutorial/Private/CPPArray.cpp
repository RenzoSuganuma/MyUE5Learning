// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPArray.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPPArray::ACPPArray()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnPrtinHello.AddDynamic(this, &ACPPArray::PrintHello);
}

void ACPPArray::PrintHello()
{
	int32 randIndex = FMath::RandRange(0, Messages.Num() - 1);

	UKismetSystemLibrary::PrintString(
		this,
		Messages[randIndex],
		1,
		1,
		FLinearColor::Black,
		5,
		TEXT("None"));
}

int32 ACPPArray::Sum(int32 a, int32 b)
{
	return a + b;
}

void ACPPArray::PressedActionPrintString()
{
	UKismetSystemLibrary::PrintString(
		this,
		"HELLLLLLOO",
		1,
		1,
		FLinearColor::Black,
		5,
		TEXT("None"));
}

// Called when the game starts or when spawned
void ACPPArray::BeginPlay()
{
	SetupInput();
}

void ACPPArray::SetupInput()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPArray::PressedH);
	InputComponent->BindAction("ActionPrintString", IE_Pressed, this, &ACPPArray::PressedActionPrintString);
}

void ACPPArray::PressedH()
{
	OnPrtinHello.Broadcast();
}

// Called every frame
void ACPPArray::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

