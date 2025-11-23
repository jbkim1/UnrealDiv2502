// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorCloseable.h"
#include "Components/StaticMeshComponent.h"

ADoorCloseable::ADoorCloseable()
{
	this->closeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CloseMesh"));
	this->closeMesh->SetupAttachment(this->GetRootComponent());
}

ADoorCloseable::~ADoorCloseable()
{
}
