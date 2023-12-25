// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPClassBase.h"
#include "MyCPPClassChild.generated.h"

/**
 * 
 */
UCLASS()
class CPLUSPLUS_TUTORIAL_API AMyCPPClassChild : public ACPPClassBase
{
	GENERATED_BODY()
	
public:
	AMyCPPClassChild();

protected:
	virtual void BeginPlay() override;

public:
	void CallChildFunc();

	int VarChildNum = 100;
};
