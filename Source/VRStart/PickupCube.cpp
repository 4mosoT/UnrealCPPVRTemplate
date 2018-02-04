// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupCube.h"
#include "Components/StaticMeshComponent.h"

void APickupCube::Pickup(USceneComponent* AttachToThisComponent)
{
	GetStaticMeshComponent()->SetSimulatePhysics(false);
	AttachToComponent(AttachToThisComponent, FAttachmentTransformRules::KeepWorldTransform);
}


void APickupCube::Drop()
{
	GetStaticMeshComponent()->SetSimulatePhysics(true);
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);


}
