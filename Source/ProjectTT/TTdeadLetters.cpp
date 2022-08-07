// Fill out your copyright notice in the Description page of Project Settings.


#include "TTdeadLetters.h"

// Sets default values
ATTdeadLetters::ATTdeadLetters()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTdeadLetters::BeginPlay()
{
	Super::BeginPlay();
	_Sand = TimeLimit;
}

// Called every frame
void ATTdeadLetters::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	_Sand -= DeltaTime;
	if (_Sand < 0)
		Teleport();
}

void ATTdeadLetters::Teleport()
{
	_Index++;
	if (_Index >= Positions.Num())
		_Index = 0;
	FVector tele = Positions[_Index];
	SetActorLocation(tele);
	OnTeleport(tele);
	_Sand = TimeLimit;
}