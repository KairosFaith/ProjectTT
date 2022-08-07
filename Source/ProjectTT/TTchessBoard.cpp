// Fill out your copyright notice in the Description page of Project Settings.


#include "TTchessBoard.h"

// Sets default values
ATTchessBoard::ATTchessBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTchessBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTchessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATTchessBoard::SelectPiece(FName piece)
{
	if (selectedPiece != piece) {
		selectedPiece  = piece;
		return true;
	}
	return false;
}

bool ATTchessBoard::CheckWin(FVector chosenSpot)
{
	if (selectedPiece == CorrectPiece) {
		float dist = FVector::Distance(chosenSpot, CorrectSpot);
		return dist<= AcceptableDeviation;
	}
	//incorrect choice
	return false;
}
