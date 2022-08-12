// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTcolorMaster.generated.h"

UCLASS()
class PROJECTTT_API ATTcolorMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATTcolorMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor TargetColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor ColorMix;
	//UFUNCTION(BlueprintCallable)
		void SetTarget(FLinearColor& color);
	//UFUNCTION(BlueprintCallable)
		bool AddColor(FLinearColor& color);
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool MinusColor(FLinearColor& color);

};
