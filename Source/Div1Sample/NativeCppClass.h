// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DIV1SAMPLE_API NativeCppClass
{
private :
	FString name;

public:
	NativeCppClass();
	~NativeCppClass();

public :
	const FString& GetName() const { return name; }
};
