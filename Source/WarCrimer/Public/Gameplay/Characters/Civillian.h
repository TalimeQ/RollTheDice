// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNpc.h"
#include "Civillian.generated.h"

/**
 * 
 */


UCLASS()
class WARCRIMER_API ACivillian : public ABaseNpc
{
	GENERATED_BODY()
	


protected:

	virtual void OnHit() override;

	virtual void BeginPlay() override;


private:

	virtual void CombatUpdate(float deltaTime) override;

	virtual void DyingUpdate(float deltaTime) override;

	virtual void SpawnedUpdate(float deltaTime) override;

	

};
