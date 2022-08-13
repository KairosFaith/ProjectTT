// Fill out your copyright notice in the Description page of Project Settings.

#include "TTcolorSwitch.h"
#include "TTcolorMaster.h"

// Sets default values
ATTcolorSwitch::ATTcolorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTcolorSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTcolorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATTcolorSwitch::Activate()
{
	OnOff = !OnOff;
	if (OnOff)
		return Master->AddColor(InteractColor);
	else
		return Master->MinusColor(InteractColor);
}