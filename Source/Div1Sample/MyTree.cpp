// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTree.h"

// Sets default values
AMyTree::AMyTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = this->BoxComponent;

	this->TreeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TreeMesh"));
	this->TreeMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyTree::BeginPlay()
{
	Super::BeginPlay();

	this->BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyTree::OnBeginOverlap);
}

// Called every frame
void AMyTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTree::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->OnCharacter();
}
