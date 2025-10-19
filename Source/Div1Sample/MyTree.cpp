// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTree.h"

#include "MyCustomObj.h"

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

	// MyCustomObj »ý¼º
	this->MyObj = NewObject<UMyCustomObj>(this);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("MyObj MyValue: %d"), this->MyObj->MyValue));
}

// Called every frame
void AMyTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTree::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("MyObj MyValue: %d"), this->MyObj->MyValue));

	if (this->SpawnObject)
	{
		FVector SpawnLocation = this->GetActorLocation() + FVector(
			FMath::RandRange(-100.0f, 100.0f), FMath::RandRange(-100.0f, 100.0f), 200.0f
		);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<AActor>(this->SpawnObject, SpawnLocation, SpawnRotation, SpawnParams);

		this->OnPostSpawnTreeObject();
	}
}
