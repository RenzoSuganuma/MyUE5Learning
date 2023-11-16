// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KismetSystemLibrary.generated.h"

/**
 * 
 */
class CPLUSPLUS_TUTORIAL_API MyDebugLogger
{
public:
	MyDebugLogger();
	~MyDebugLogger();

	UFUNCTION(BlueprintCallable, Category = "DEBUG")
	void OutputLogToDisplay();
};
