// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MyTree.generated.h"

UCLASS()
class DIV1SAMPLE_API AMyTree : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess="true"))
	UStaticMeshComponent* TreeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxComponent;

private :
	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<AActor> SpawnObject;

	UPROPERTY()
	class UMyCustomObj* MyObj;
	
public:	
	// Sets default values for this actor's properties
	AMyTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPostSpawnTreeObject();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
