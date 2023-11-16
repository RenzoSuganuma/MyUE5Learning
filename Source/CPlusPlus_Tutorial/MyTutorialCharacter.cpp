// Fill out your copyright notice in the Description page of Project Settings.
#include "MyTutorialCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AMyTutorialCharacter::AMyTutorialCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void AMyTutorialCharacter::BeginPlay()
{
	Super::BeginPlay();
}
// Called every frame
void AMyTutorialCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Output Count every Frame
	iCount++;
	OutputLog(FString::FormatAsNumber(iCount));
}
// Called to bind functionality to input
void AMyTutorialCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
void AMyTutorialCharacter::SpawnMyActor()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(myactorBPToSpawn, spawnPos, spawnParams);
}

void AMyTutorialCharacter::OutputLog(FString sMessage)
{
	UKismetSystemLibrary::PrintString(this, sMessage, 1, 0, FColor::Black, 2.f, TEXT("None"));
}