// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyCustomObj.generated.h"

/**
 * 
 */
UCLASS()
class DIV1SAMPLE_API UMyCustomObj : public UObject
{
	GENERATED_BODY()

public :
	UMyCustomObj();
	~UMyCustomObj();

public :
	int32 MyValue;	
};
