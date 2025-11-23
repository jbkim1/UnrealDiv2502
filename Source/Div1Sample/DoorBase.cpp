// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ADoorBase::ADoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	this->SetRootComponent(this->DoorMesh);

	this->collisionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionArea"));
	this->collisionArea->SetupAttachment(this->DoorMesh);
}

// Called when the game starts or when spawned
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();

	this->collisionArea->OnComponentBeginOverlap.AddDynamic(this, &ADoorBase::OnBeginOverlap);
}

// Called every frame
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorBase::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->Interact();
}
