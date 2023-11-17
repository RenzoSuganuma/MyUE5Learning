// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalculation.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API ACPPCalculation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPCalculation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	const float fDuration = 10.f;

	const FColor TextColor = FColor(0., .66, 1.);

	int32 iValA = 7;
	int32 iValB = 3;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
