// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Misc/BaseProjectine.h"
#include "PlayerBullet.generated.h"

/**
 * 
 */
UCLASS()
class WARCRIMER_API APlayerBullet : public ABaseProjectine
{
	GENERATED_BODY()

	virtual void OnInteraction(AActor* overlapingActor) override;
	
	
};
