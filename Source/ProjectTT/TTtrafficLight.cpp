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

bool ATTtrafficLight::TrafficLightTick(float DeltaTime)
{
	FVector playerLocation = PlayerCharacter->GetActorLocation();
	_Sand -= DeltaTime;
	if (_Sand <= 0) {

		if (GreenOrRed)//if green
			lastGreenPosition = playerLocation;
		GreenOrRed = !GreenOrRed;
		if (GreenOrRed)
			_Sand = GreenTime;
		else
			_Sand = RedTime;

		return true;
	}
	return false;
}

bool ATTtrafficLight::OnDetectPlayer(AProjectTTCharacter* detectedCharacter)
{//true if player yeeted back
	FVector playerLocation = PlayerCharacter->GetActorLocation();
	if (GreenOrRed)
	{
		//do nothing
	}
	else//if red
	{
		float displacement = (playerLocation - lastGreenPosition).Length();
		if (displacement > 1) {
			PlayerCharacter->SetActorLocation(playerStartPoint);
			return true;
		}
	}
	return false;
}