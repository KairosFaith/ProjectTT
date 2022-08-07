// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTchessBoard.h"
#include "TTchessPiece.generated.h"

UCLASS()
class PROJECTTT_API ATTchessPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATTchessPiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ATTchessBoard* ChessBoard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName PieceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DefaultPosition;
	UFUNCTION(BlueprintCallable)
		bool SelectThis();
};
