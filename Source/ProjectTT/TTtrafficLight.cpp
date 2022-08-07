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
	//if(_Started)
		TrafficLightTick(DeltaTime);
}

bool ATTtrafficLight::TrafficLightTick(float DeltaTime)
{
	_Sand -= DeltaTime;
	if (_Sand <= 0) {
		GreenOrRed = !GreenOrRed;
		if (GreenOrRed) {
			_Sand = GreenTime;
			GreenLight();
		}
		else {
			_Sand = RedTime;
			RedLight();
		}
		return true;
	}
	return false;
}

bool ATTtrafficLight::OnDetectPlayer(AProjectTTCharacter* detectedCharacter)
{//true if player yeeted back
	FVector playerLocation = detectedCharacter->GetActorLocation();
	if (!_Started) {
		playerStartPoint = playerLocation;// might change due to game design
		_Started = true;
	}
	if (GreenOrRed)
		lastGreenPosition = playerLocation;
	else//if red
	{
		float displacement = (playerLocation - lastGreenPosition).Length();
		if (displacement > 1) {
			detectedCharacter->SetActorLocation(playerStartPoint);
			OnPlayerYeet(playerStartPoint);
			return true;
		}
	}
	return false;
}