// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

UCLASS()
class DIV1SAMPLE_API ADoorBase : public AActor
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleAnywhere, Category = "Door", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere, Category = "Door", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* collisionArea;
	
public:	
	// Sets default values for this actor's properties
	ADoorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void Interact();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
