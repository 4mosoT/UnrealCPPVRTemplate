// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPlayerPawn.generated.h"

class IHeadMountedDisplay;
class UCameraComponent;
class USceneComponent;
class UTextRenderComponent;
class AHand;
UCLASS()
class VRSTART_API AVRPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AHand> ControllerBlueprint;

private:
	IHeadMountedDisplay* HMD;
	AHand* RightController;
	AHand* LeftController;


	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultPlayerSceneRoot;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VROrigin;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	//Text Render For Logging And Debug Purposes
	UPROPERTY(VisibleAnywhere)
	UTextRenderComponent* DebugText;
	void SetDebugText(FText Text);

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TriggerLeftPressed();
	void TriggerRightPressed();

	void TriggerLeftReleased();
	void TriggerRightReleased();
};
