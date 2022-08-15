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
		Teleport();
		return false;
	}
	else if (!atFinal) {
		SetActorLocation(FinalPosition);
		OnTeleport(FinalPosition);
		atFinal = true;
		return false;
	}
	else {
		WinPuzzle();
		return true;
	}
}
bool ATTrubberDuck::SelectThis()
{
	if (atFinal)
		WinPuzzle();
	return atFinal;
}
void ATTrubberDuck::WinPuzzle()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You win!"));
}
FVector ATTrubberDuck::Teleport()
{
	int r = FMath::RandRange(0, Positions.Num() - 1);
	FVector positionToTele = Positions[r];
	SetActorLocation(positionToTele);
	Positions.Remove(positionToTele);
	OnTeleport(positionToTele);
	return positionToTele;
}
