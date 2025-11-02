// Fill out your copyright notice in the Description page of Project Settings.


#include "NativeCppClass.h"

NativeCppClass::NativeCppClass()
{
	this->name = TEXT("Native C++ Class");

	UE_LOG(LogTemp, Log, TEXT("NativeCppClass Constructor called. Name: %s"), *this->name);
}

NativeCppClass::~NativeCppClass()
{
	UE_LOG(LogTemp, Log, TEXT("NativeCppClass Destructor called. Name: %s"), *this->name);
}
