// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Gameplay/Misc/PlayerBullet.h"

void APlayerBullet::OnInteraction(AActor * overlapingActor)
{
	UE_LOG(LogTemp, Warning, TEXT("BULLET INTERACTED!"));
}
