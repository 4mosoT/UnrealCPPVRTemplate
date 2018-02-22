// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Weapons/Projectile.h"
#include "Engine/World.h"



// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun Mesh"));
	RootComponent = GunMesh;

}

bool AGun::Pickup(USceneComponent * AttachToThisComponent, FName Socket)
{
	
	GunMesh->SetSimulatePhysics(false);
	if (!Socket.IsNone()) {
		AttachToComponent(AttachToThisComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, Socket);
		GunMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}else {
		AttachToComponent(AttachToThisComponent, FAttachmentTransformRules::KeepWorldTransform);
	}
	return true;
	
}

void AGun::Drop()
{
	GunMesh->SetSimulatePhysics(true);
	GunMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}


void AGun::Fire()
{
	// Play a sound if there is one
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	GetWorld()->SpawnActor<AProjectile>(ProjectileClass, GunMesh->GetSocketLocation(TEXT("Muzzle")), GunMesh->GetSocketRotation(TEXT("Muzzle")));
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

