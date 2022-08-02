// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTdeadLetters.generated.h"

UCLASS()
class PROJECTTT_API ATTdeadLetters : public AActor
{
	GENERATED_BODY()
	int _Index = 0;
	float _Sand = 0;
public:	
	// Sets default values for this actor's properties
	ATTdeadLetters();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector Positions[9];
	float TimeLimit;
	void Teleport();
};
