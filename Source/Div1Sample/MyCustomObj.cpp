// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCustomObj.h"

UMyCustomObj::UMyCustomObj()
{
	this->MyValue = 42;
}

UMyCustomObj::~UMyCustomObj()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MyCustomObj Destroyed"));
}