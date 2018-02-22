// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interfaces/PickableActorInterface.h"
#include "PickupCube.generated.h"

/**
 * 
 */
UCLASS()
class VRSTART_API APickupCube : public AStaticMeshActor, public IPickableActorInterface
{
	GENERATED_BODY()
	
public:
	virtual bool Pickup(USceneComponent* AttachToThisComponent, FName Socket) override;
	virtual void Drop() override;

	
};
