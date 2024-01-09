// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoopHoge.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API APoopHoge : public AActor
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "My Functions")
	void SayHoge();
	
public:	
	// Sets default values for this actor's properties
	APoopHoge();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
