// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/PointLightComponent.h"
#include "CPPConstractionScript.generated.h"

UCLASS()
class CPLUSPLUS_TUTORIAL_API ACPPConstractionScript : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPConstractionScript();

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPointLightComponent> PointLight;

	UPROPERTY(EditAnywhere, Category = "Point Light")
	bool bIsVisible = 0;

	UPROPERTY(EditAnywhere, Category = "Point Light")
	float fItensity = 5000.f;

	UPROPERTY(EditAnywhere, Category = "Point Light")
	FColor LightColor = FColor::White;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

private:
	const float fDuration = 10.f;

	const FColor TextColor = FColor(0., .66, 1.);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
