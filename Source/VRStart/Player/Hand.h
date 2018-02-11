// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlobalStructs.h"
#include "Hand.generated.h"

class UMotionControllerComponent;
class USteamVRChaperoneComponent;
class UHandAnimInstance;
class USphereComponent;
class UHapticFeedbackEffect_Base;

UCLASS()
class VRSTART_API AHand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void InvertSkeletalMesh();
	void SetGripStatus(EGripState GripState);

	UPROPERTY(EditDefaultsOnly, Category = "Haptic")
	UHapticFeedbackEffect_Base* HapticBase;
	UPROPERTY(EditDefaultsOnly, Category = "Haptic")
	float HapticForce = .5f;

	void GrabActor(FName Socket = TEXT(""));
	void ReleaseActor();
	AActor* GetAttachedActor();
	bool IsGrabbing();

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultHandSceneRoot;
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(VisibleAnywhere)
	USteamVRChaperoneComponent* Chaperone;
	UPROPERTY(VisibleAnywhere)
	USphereComponent* CollisionSphere;

	bool bWantsToGrab = false;

	class UHandAnimInstance* AnimInstance;

	TArray<AActor*> OverlappedActors;
	AActor* AttachedActor;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
