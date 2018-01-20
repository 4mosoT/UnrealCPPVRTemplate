// Fill out your copyright notice in the Description page of Project Settings.

#include "Hand.h"
#include "MotionControllerComponent.h"


// Sets default values
AHand::AHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultHandSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultHandSceneRoot"));
	RootComponent = DefaultHandSceneRoot;
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion Controller Component"));
	MotionController->AttachTo(GetRootComponent());

}

// Called when the game starts or when spawned
void AHand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

