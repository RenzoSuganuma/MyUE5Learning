// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyTutorialCharacter.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API AMyTutorialCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AMyTutorialCharacter();
	// Spawn My Actor
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void SpawnMyActor();
	// OutPut Log ToDisplay
	UFUNCTION(BlueprintCallable , Category = "Debug_Log")
	void OutputLog(FString sMessage);
	// 
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> myactorBPToSpawn;
	UPROPERTY(EditAnywhere)
	FTransform spawnPos;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int iCount = 0;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};