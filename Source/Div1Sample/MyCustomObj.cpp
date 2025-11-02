// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCustomObj.h"
#include "NativeCppClass.h"

UMyCustomObj::UMyCustomObj()
{
	this->MyValue = 42;
}

UMyCustomObj::~UMyCustomObj()
{
}

// shared ptr을 weak ptr로 받는 것 확인.
void UMyCustomObj::setNativeCppObj(TWeakPtr<class NativeCppClass> InNativeCppObj)
{
	NativeCppObj = InNativeCppObj;

	// weak ptr은 객체가 존재하는지 확인하고 사용 해야 함.
	if (TSharedPtr<NativeCppClass> Pinned = NativeCppObj.Pin())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("NativeCppClass Value: %s in custom obj"), *Pinned->GetName()));
	}
}