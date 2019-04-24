// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseNpc.generated.h"

UENUM(Blueprintable, BlueprintType) enum ENpcStatus
{
	ENpcIdle,
	ENpcCombat,
	ENpcWander,
	ENpcDying,
	ENpcSpawned
};

UCLASS(abstract)
class WARCRIMER_API ABaseNpc : public AActor
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Npc")
		TEnumAsByte<ENpcStatus> currentNpcStatus { ENpcStatus::ENpcIdle };
	
	UPROPERTY(BlueprintReadWrite, Category = "Lives")
	int hp = 3;

private:

	void (ABaseNpc::*stateUpdate)(float) = nullptr;

public:	
	// Sets default values for this actor's properties
	ABaseNpc();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void UpdateState(float deltaTime);
	
	UFUNCTION(BlueprintCallable, Category = "state")
	virtual void SwitchState(TEnumAsByte<ENpcStatus> newState);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	virtual void CombatUpdate(float deltaTime) PURE_VIRTUAL(ABaseNpc::CombatUpdate(), ;);

	virtual void IdleUpdate(float deltaTime)  PURE_VIRTUAL(ABaseNpc::IdleUpdate(), ;);

	virtual void DyingUpdate(float deltaTime)  PURE_VIRTUAL(ABaseNpc::DyingUpdate(), ;);

	virtual void SpawnedUpdate(float deltaTime) PURE_VIRTUAL(ABaseNpc::SpawnedUpdate(), ;);

	virtual void WanderUpdate(float deltaTime) PURE_VIRTUAL(ABaseNpc::WanderUpdate(), ;);
	
};
