// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableActorInterface.h"
#include "Gun.generated.h"



UCLASS()
class VRSTART_API AGun : public AActor, public IPickableActorInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	virtual bool Pickup(USceneComponent* AttachToThisComponent, FName Socket) override;
	virtual void Drop() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GunMesh;
	
};
