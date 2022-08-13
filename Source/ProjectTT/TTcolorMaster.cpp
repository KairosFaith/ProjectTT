// Fill out your copyright notice in the Description page of Project Settings.


#include "TTcolorMaster.h"

// Sets default values
ATTcolorMaster::ATTcolorMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTcolorMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTcolorMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATTcolorMaster::SetTarget(FLinearColor& color)
{
	TargetColor = color;
}
bool ATTcolorMaster::AddColor(FLinearColor& color)
{
	ColorMix += color;
	bool success = ColorMix == TargetColor;
	OnChangeColor(success,ColorMix);
	return success;
}
bool ATTcolorMaster::MinusColor(FLinearColor& color)
{
	ColorMix -= color;
	bool success = ColorMix == TargetColor;
	OnChangeColor(success, ColorMix);
	return success;
}