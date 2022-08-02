// Fill out your copyright notice in the Description page of Project Settings.


#include "TTtrafficLight.h"

// Sets default values
ATTtrafficLight::ATTtrafficLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTtrafficLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTtrafficLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

