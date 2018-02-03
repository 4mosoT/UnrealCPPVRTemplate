// Fill out your copyright notice in the Description page of Project Settings.

#include "Hand.h"
#include "MotionControllerComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SteamVRChaperoneComponent.h"
#include "AnimationsInstances/HandAnimInstance.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AHand::AHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DefaultHandSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultHandSceneRoot"));
	//RootComponent = DefaultHandSceneRoot;
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("Motion Controller Component"));
	//MotionController->SetupAttachment(RootComponent);
	RootComponent = MotionController;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SkeletalMesh->SetupAttachment(MotionController);
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->SetupAttachment(SkeletalMesh);
	Chaperone = CreateDefaultSubobject<USteamVRChaperoneComponent>(TEXT("Chaperone"));
}

// Called when the game starts or when spawned
void AHand::BeginPlay()
{
	Super::BeginPlay();
	AnimInstance = Cast<UHandAnimInstance>(SkeletalMesh->GetAnimInstance());

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AHand::OnOverlapBegin);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AHand::OnOverlapEnd);
	

}

// Called every frame
void AHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHand::InvertSkeletalMesh()
{
	//SkeletalMesh->SetWorldRotation(FRotator(0, 0, 180));
	SkeletalMesh->SetWorldScale3D(FVector(1, 1, -1));
	MotionController->Hand = EControllerHand::Left;
	
}

void AHand::SetGripStatus(EGripState GripState)
{
	AnimInstance->GripStatus = GripState;
}


void AHand::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Other Actor is the actor that triggered the event. Check that is not ourself.
	if ((OtherComp != nullptr))
	{
		UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(OtherComp);
		if (Mesh && Mesh->IsSimulatingPhysics()) {
			GetWorld()->GetFirstPlayerController()->PlayHapticEffect(HapticBase, MotionController->Hand, HapticForce);
			SetGripStatus(EGripState::CanGrab);
		}
	}
}

void AHand::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	SetGripStatus(EGripState::Open);
}

void AHand::GrabActor()
{
	//for (AActor* Actor : CollisionSphere->GetOverlappingActors) {
		//UKismetSystemLibrary::DoesImplementInterface(Actor, )


	//}
}
