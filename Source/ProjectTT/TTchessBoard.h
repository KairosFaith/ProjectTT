// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTchessBoard.generated.h"

using namespace std;
UCLASS()
class PROJECTTT_API ATTchessBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATTchessBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FName selectedPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName CorrectPiece;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector CorrectSpot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AcceptableDeviation = 1;

	UFUNCTION(BlueprintCallable)
		bool SelectPiece(FName piece);
	UFUNCTION(BlueprintCallable)
		bool CheckWin(FVector chosenSpot);
};
