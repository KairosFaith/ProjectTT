// Fill out your copyright notice in the Description page of Project Settings.


#include "TTrubberDuck.h"

// Sets default values
ATTrubberDuck::ATTrubberDuck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTrubberDuck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTrubberDuck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATTrubberDuck::SensePlayer()
{
	if (Positions.Num() > 0)
	{
		//teleport to first position
		//Teleport();
		return false;
	}
	else if (!atFinal) {
		SetActorLocation(FinalPosition);
		atFinal = true;
		return false;
	}
	else {
		//rubber duck dissapear, go to next puzzle
		return true;
	}
}
FVector ATTrubberDuck::Teleport()
{
	int r = FMath::RandRange(0, Positions.Num());
	FVector positionToTele = Positions[r];
	SetActorLocation(positionToTele);
	Positions.Remove(positionToTele);
	return positionToTele;
}