// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "ProjectTTPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;

UCLASS()
class AProjectTTPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AProjectTTPlayerController();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void OnTouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location);
	void OnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location);

private:
	bool bInputPressed; // Input is bring pressed
	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

//TOTEM stuff
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float InteractRange = 150;
	UFUNCTION(BlueprintImplementableEvent)
		void OnClick(AActor* actor);
	UFUNCTION(BlueprintImplementableEvent)
		void OnTick();
	UFUNCTION(BlueprintCallable)
		bool CheckDistanceObjectPawn(AActor* actor);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ClickedLocation;
};


