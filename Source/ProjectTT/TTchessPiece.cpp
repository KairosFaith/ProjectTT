// Fill out your copyright notice in the Description page of Project Settings.

#include "TTchessPiece.h"
#include "TTchessBoard.h"

// Sets default values
ATTchessPiece::ATTchessPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTchessPiece::BeginPlay()
{
	Super::BeginPlay();
	DefaultPosition = GetActorLocation();
}

// Called every frame
void ATTchessPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATTchessPiece::SelectThis()
{
	return ChessBoard->SelectPiece(PieceName);
}

