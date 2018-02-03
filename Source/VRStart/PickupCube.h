// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PickableActorInterface.h"
#include "PickupCube.generated.h"

/**
 * 
 */
UCLASS()
class VRSTART_API APickupCube : public AStaticMeshActor, public IPickableActorInterface
{
	GENERATED_BODY()
	
public:
	virtual void Pickup() override;
	virtual void Drop() override;

	
};
