// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpItem.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickUpItem::APickUpItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// root - box component
	// ㄴ body - static mesh component
	this->collision = CreateDefaultSubobject<UBoxComponent>(TEXT("collision"));
	this->SetRootComponent(this->collision);

	this->body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body"));
	this->body->SetupAttachment(this->GetRootComponent());

	// 기본값을 체력 회복 아이템으로 설정
	this->type = EPickUpItemType::HealthRestore;
	this->value = 0;
}

// Called when the game starts or when spawned
void APickUpItem::BeginPlay()
{
	Super::BeginPlay();

	this->collision->OnComponentBeginOverlap.AddDynamic(this, &APickUpItem::OnBeginOverlap);
}

// Called every frame
void APickUpItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpItem::OnBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	this->OnPickUp(this->type, this->value);

	this->Destroy();
}
