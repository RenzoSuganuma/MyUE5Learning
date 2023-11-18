// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPEventDispatcher.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API ACPPEventDispatcher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPEventDispatcher();

	UFUNCTION()
	void PrintHello();

	int32 Sum(int32 a, int32 b);

	void PressedActionPrintString();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);
	UPROPERTY(BlueprintAssignable, Category = "CPP_BP")
	FPrintHelloDelegate OnPrintHello;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FString Message = "C++ Hellow Fucking World";

	void SetupInput();

	void PressedPopMessage();

	void PressedH();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
