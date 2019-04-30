// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Gameplay/Characters/Civillian.h"



void ACivillian::DyingUpdate(float deltaTime)
{
}

void ACivillian::SpawnedUpdate(float deltaTime)
{
}

void  ACivillian::BeginPlay()
{
	Super::BeginPlay();

}

void ACivillian::CombatUpdate(float deltaTime)
{
}

void  ACivillian::OnHit()
{
	UE_LOG(LogTemp, Warning, TEXT("Civillian hit!"));
}