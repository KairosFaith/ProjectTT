// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTcolorMaster.h"
#include "TTcolorSwitch.generated.h"

UCLASS()
class PROJECTTT_API ATTcolorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATTcolorSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool OnOff = false;//true if on
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor InteractColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ATTcolorMaster* Master;
	UFUNCTION(BlueprintCallable)
		bool Activate();
};
