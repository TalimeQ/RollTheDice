// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Gameplay/Characters/Civillian.h"

void ACivillian::IdleUpdate(float deltaTime)
{

}

void ACivillian::DyingUpdate(float deltaTime)
{
}

void ACivillian::SpawnedUpdate(float deltaTime)
{
}

void ACivillian::WanderUpdate(float deltaTime)
{
}

void ACivillian::CombatUpdate(float deltaTime)
{
}

void  ACivillian::OnHit()
{
	UE_LOG(LogTemp, Warning, TEXT("Civillian hit!"));
}