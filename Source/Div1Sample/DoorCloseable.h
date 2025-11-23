// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "DoorCloseable.generated.h"

/**
 * 
 */
UCLASS()
class DIV1SAMPLE_API ADoorCloseable : public ADoorBase
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* closeMesh;

public :
	ADoorCloseable();
	~ADoorCloseable();
};
