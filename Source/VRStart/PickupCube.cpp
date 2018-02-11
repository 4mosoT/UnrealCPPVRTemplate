// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupCube.h"
#include "Components/StaticMeshComponent.h"

bool APickupCube::Pickup(USceneComponent* AttachToThisComponent, FName Socket)
{
	bool result = false;
	if (Socket.IsNone()) {
		GetStaticMeshComponent()->SetSimulatePhysics(false);
		AttachToComponent(AttachToThisComponent, FAttachmentTransformRules::KeepWorldTransform);
		result = true;
	}
	return result;
}


void APickupCube::Drop()
{
	GetStaticMeshComponent()->SetSimulatePhysics(true);
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);


}
