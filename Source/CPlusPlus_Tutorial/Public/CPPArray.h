// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPArray.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API ACPPArray : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPArray();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FprintHelloDelegate);
	UPROPERTY(BlueprintAssignable, Category = "CPP_BP");
	FprintHelloDelegate OnPrtinHello;

	UFUNCTION()
	void PrintHello();

	int32 Sum(int32 a, int32 b);

	void PressedActionPrintString();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetupInput();

	void PressedH();

	TArray<FString> Messages = { TEXT("C++ Hello World!"), TEXT("你好 世界!"), TEXT("Bonjour le monde!"), TEXT("Hallo Welt!"), TEXT("こんにちは世界!") };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
