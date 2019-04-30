// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseNpc.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "Runtime/Engine/Classes/Components/InterpToMovementComponent.h"



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
	int randomSpriteIndex = FMath::RandRange(0, npcSpritePool.Num() - 1);
	this->npcAnimSprites = npcSpritePool[randomSpriteIndex].npcAnimMapElement;
	SwitchState(ENpcStatus::ENpcIdle);

}

void ABaseNpc::UpdateState(float deltaTime)
{
	check(stateUpdate) (*this.*stateUpdate)(deltaTime);
}
void ABaseNpc::SwitchState(TEnumAsByte<ENpcStatus> newState)
{
	currentNpcStatus = newState;
	switch (newState)
	{
		case ENpcStatus::ENpcIdle:
			SwitchToIdle();
			break;
		case ENpcStatus::ENpcDying:
			SwitchToDying();
			break;
		case ENpcStatus::ENpcWander:
			SwitchToWander();
			break;
		case ENpcStatus::ENpcCombat:
			SwitchToCombat();
			break;
		case ENpcStatus::ENpcSpawned:
			SwitchToSpawned();
			break;
	}
}

// Called every frame
void ABaseNpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateState(DeltaTime);
}

void ABaseNpc::IdleUpdate(float deltaTime)
{
	


}

void  ABaseNpc::DyingUpdate(float deltaTime)
{
}

void  ABaseNpc::SpawnedUpdate(float deltaTime)
{
}

void  ABaseNpc::WanderUpdate(float deltaTime)
{

}

void  ABaseNpc::CombatUpdate(float deltaTime)
{

}

void  ABaseNpc::SwitchToIdle()
{
	stateUpdate = &ABaseNpc::IdleUpdate;
	currentNpcAnimationStatus = ENpcAnimStatus::ENpcIdleAnim;
	SwitchAnimation();
}

void  ABaseNpc::SwitchToWander()
{
	stateUpdate = &ABaseNpc::WanderUpdate;
	currentNpcAnimationStatus = ENpcAnimStatus::ENpcWalkAnim;
	SwitchAnimation();
}

void  ABaseNpc::SwitchToDying()
{
	stateUpdate = &ABaseNpc::DyingUpdate;
	currentNpcAnimationStatus = ENpcAnimStatus::ENpcDeathAnim;
	SwitchAnimation();
}

void  ABaseNpc::SwitchToSpawned()
{
	stateUpdate = &ABaseNpc::SpawnedUpdate;
	currentNpcAnimationStatus = ENpcAnimStatus::ENpcSpawnedAnim;
	SwitchAnimation();
}

void  ABaseNpc::SwitchToCombat()
{
	stateUpdate = &ABaseNpc::CombatUpdate;
	currentNpcAnimationStatus = ENpcAnimStatus::ENpcCombatAnim;
	SwitchAnimation();
}

TEnumAsByte<ENpcStatus>  ABaseNpc::GetState()
{
	return currentNpcStatus;
}

void  ABaseNpc::SwitchAnimation()
{
	UPaperFlipbook** newAnimation = npcAnimSprites.Find(currentNpcAnimationStatus);
	if (npcRepresentation && newAnimation)
	{
		npcRepresentation->SetFlipbook(*newAnimation);
	}
	
}

void ABaseNpc::SetAnimationState(TEnumAsByte<ENpcAnimStatus> newAnimationStatus)
{
	currentNpcAnimationStatus = newAnimationStatus;
}