// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPInputEvent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPPInputEvent::ACPPInputEvent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPInputEvent::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();
}

void ACPPInputEvent::PressedActionPrintString()
{
	UKismetSystemLibrary::PrintString(this, "Mouse Button Now!", 1, 1, FColor::Cyan, 10, TEXT("None"));
}

void ACPPInputEvent::SetupInput()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPInputEvent::PressedH);
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPInputEvent::ReleasedH);

	InputComponent->BindAction("ActionPrintString", IE_Pressed, this, &ACPPInputEvent::PressedActionPrintString);
}

void ACPPInputEvent::PressedH()
{
	UKismetSystemLibrary::PrintString(this, "H Pressed", 1, 1, FColor::Cyan, 10, TEXT("None"));
}

void ACPPInputEvent::ReleasedH()
{
	UKismetSystemLibrary::PrintString(this, "H Released", 1, 1, FColor::Cyan, 10, TEXT("None"));
}


// Called every frame
void ACPPInputEvent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

