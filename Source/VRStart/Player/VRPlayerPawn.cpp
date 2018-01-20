// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlayerPawn.h"
#include "HeadMountedDisplay.h"
#include "Engine/Engine.h"
#include "IXRTrackingSystem.h"

#include "Camera/CameraComponent.h"


// Sets default values
AVRPlayerPawn::AVRPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultPlayerSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultPlayerSceneRoot"));
	RootComponent = DefaultPlayerSceneRoot;
	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin2"));
	VROrigin->AttachTo(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera2"));
	Camera->AttachTo(VROrigin);

}

// Called when the game starts or when spawned
void AVRPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	HMD = GEngine->XRSystem->GetHMDDevice();

	//Change for the distinct systems the origin tracking
	GEngine->XRSystem->SetTrackingOrigin(EHMDTrackingOrigin::Floor);
	
	
	
}

// Called every frame
void AVRPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GEngine) {
		
		uint32 type = HMD->GetHMDDeviceType();
		const int32 MyNumberKey = 0;
		GEngine->AddOnScreenDebugMessage(MyNumberKey, 5.f, FColor::Red, FString::Printf(TEXT("\n\n\n\nName is: %i"),type));
	}

}

// Called to bind functionality to input
void AVRPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

