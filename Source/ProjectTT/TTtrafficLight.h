// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectTTCharacter.h"
#include "TTtrafficLight.generated.h"

UCLASS()
class PROJECTTT_API ATTtrafficLight : public AActor
{
	GENERATED_BODY()
	float _Sand = 0;
	FVector lastGreenPosition = FVector();
	bool _Started = false;
public:	
	// Sets default values for this actor's properties
	ATTtrafficLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GreenTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RedTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool GreenOrRed; //true green false red

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector playerStartPoint;

	UFUNCTION(BlueprintCallable)
		bool TrafficLightTick(float DeltaTime);//return true if light changed
	UFUNCTION(BlueprintCallable)
		bool OnDetectPlayer(AProjectTTCharacter* detectedCharacter);//true if player yeeted back
	UFUNCTION(BlueprintImplementableEvent)
		void GreenLight();
	UFUNCTION(BlueprintImplementableEvent)
		void RedLight();
	UFUNCTION(BlueprintImplementableEvent)
		void OnPlayerYeet(FVector position);

};
