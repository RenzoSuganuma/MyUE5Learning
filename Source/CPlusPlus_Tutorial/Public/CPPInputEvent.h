// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPInputEvent.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API ACPPInputEvent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPInputEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetupInput();


	void PressedH();
	void ReleasedH();

	void PressedActionPrintString();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
