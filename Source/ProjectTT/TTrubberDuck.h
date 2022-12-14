// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTrubberDuck.generated.h"

UCLASS()
class PROJECTTT_API ATTrubberDuck : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATTrubberDuck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Positions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector FinalPosition;
	FVector Teleport();
	bool atFinal = false;
	UFUNCTION(BlueprintCallable)
		bool SensePlayer();
	UFUNCTION(BlueprintCallable)
		bool SelectThis();
	UFUNCTION(BlueprintImplementableEvent)
		void OnTeleport(FVector position);
	UFUNCTION(BlueprintImplementableEvent)
		void WinPuzzle();
};