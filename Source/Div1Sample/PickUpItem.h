// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpItem.generated.h"

UENUM(BlueprintType)
enum class EPickUpItemType : uint8
{
	HealthRestore UMETA(DisplayName = "HealthRestore"),
	ScoreIncrease UMETA(DisplayName = "ScoreIncrease"),
};

UCLASS()
class DIV1SAMPLE_API APickUpItem : public AActor
{
	GENERATED_BODY()

public :
	// 1: 체력 회복
	// 2: 점수 증가
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sample")
	EPickUpItemType type;

	// 효과가 얼마나 적용되는지?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sample")
	int value;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Sample")
	class UStaticMeshComponent* body;

	UPROPERTY(VisibleDefaultsOnly, Category = "Sample")
	class UBoxComponent* collision;
	
public:	
	// Sets default values for this actor's properties
	APickUpItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected :
	// BP에서 정의되는 구체적인 아이템의 기능.
	UFUNCTION(BlueprintImplementableEvent)
	void OnPickUp(EPickUpItemType pickUp_type, int pickUp_value);

private :
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};