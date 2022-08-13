// Fill out your copyright notice in the Description page of Project Settings.

#include "TTcolorGuide.h"
#include "TTcolorMaster.h"

// Sets default values
ATTcolorGuide::ATTcolorGuide()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTcolorGuide::BeginPlay()
{
	Super::BeginPlay();
	Master->SetTarget(TargetColor);
}

// Called every frame
void ATTcolorGuide::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

