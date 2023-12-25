// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPClassBase.h"
#include "CPPClassChild.generated.h"

/**
 * 
 */
UCLASS()
class CPLUSPLUS_TUTORIAL_API ACPPClassChild : public ACPPClassBase
{
	GENERATED_BODY()
	
public:
	ACPPClassChild();

protected:
	virtual void BeginPlay() override;

public:
	void CallChildFunc();

	int VarChildNum = 100;
};
