// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseNpc.h"


// Sets default values
ABaseNpc::ABaseNpc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseNpc::BeginPlay()
{
	Super::BeginPlay();
	stateUpdate = &ABaseNpc::IdleUpdate;
	
}

void ABaseNpc::UpdateState(float deltaTime)
{
	check(stateUpdate) (*this.*stateUpdate)(deltaTime);
}
void ABaseNpc::SwitchState(TEnumAsByte<ENpcStatus> newState)
{
	switch (newState)
	{
		case ENpcStatus::ENpcIdle:
			stateUpdate = &ABaseNpc::IdleUpdate;
			break;
		case ENpcStatus::ENpcDying:
			stateUpdate = &ABaseNpc::DyingUpdate;
			break;
		case ENpcStatus::ENpcWander:
			stateUpdate = &ABaseNpc::WanderUpdate;
			break;
		case ENpcStatus::ENpcCombat:
			stateUpdate = &ABaseNpc::CombatUpdate;
			break;
		case ENpcStatus::ENpcSpawned:
			stateUpdate = &ABaseNpc::SpawnedUpdate;
			break;
	}
}

// Called every frame
void ABaseNpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateState(DeltaTime);
}


