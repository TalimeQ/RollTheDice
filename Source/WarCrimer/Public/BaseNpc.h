// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseNpc.generated.h"

class UPaperFlipbookComponent;
class UPaperFlipbook;



UENUM(Blueprintable, BlueprintType) enum ENpcStatus
{
	ENpcIdle,
	ENpcCombat,
	ENpcWander,
	ENpcDying,
	ENpcSpawned
};

UENUM(Blueprintable, BlueprintType) enum ENpcAnimStatus
{
	ENpcIdleAnim,
	ENpcWalkAnim,
	ENpcDeathAnim,
	ENpcDeadAnim,
	ENpcCombatAnim,
	ENpcSpawnedAnim,
	ENpcBonusAnim,
	ENpcBonus2Anim,
	EnpcBonus3Anim
};

USTRUCT(Blueprintable, BlueprintType) struct FSpriteRepresentation
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Sprites")
		TMap<TEnumAsByte<ENpcAnimStatus>, UPaperFlipbook*> npcAnimMapElement;

};


UCLASS(abstract)
class WARCRIMER_API ABaseNpc : public AActor
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Npc")
		TArray<FSpriteRepresentation> npcSpritePool;

	UPROPERTY(BlueprintReadWrite, Category = "Npc")
		TEnumAsByte<ENpcStatus> currentNpcStatus { ENpcStatus::ENpcIdle };

	UPROPERTY(BlueprintReadWrite, Category = "Npc")
		TEnumAsByte<ENpcAnimStatus> currentNpcAnimationStatus{ ENpcAnimStatus::ENpcIdleAnim };

	UPROPERTY(BlueprintReadWrite, Category = "Npc")
		UPaperFlipbookComponent* npcRepresentation = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "Lives")
		int hp = 3;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Sprite")
		TMap<TEnumAsByte<ENpcAnimStatus>, UPaperFlipbook*> npcAnimSprites;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		FVector2D minMovementRange {-200,-30};

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		FVector2D maxMovementRange {200,50};
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float wanderWaitTime = 5.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float combatSpeedBias = 10.0f;


private:

	void (ABaseNpc::*stateUpdate)(float) = nullptr;

public:	
	// Sets default values for this actor's properties
	ABaseNpc();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void UpdateState(float deltaTime);
	
	UFUNCTION(BlueprintCallable, Category = "State")
	virtual void SwitchState(TEnumAsByte<ENpcStatus> newState);

	UFUNCTION(BlueprintCallable, Category = "Combat")
	virtual void OnHit()  PURE_VIRTUAL(ABaseNpc::OnHit(), ;);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "State")
	TEnumAsByte<ENpcStatus> GetState();

	/*
		Manually change animation state of NPC
		Only changes state NOT ANIMATION
		Use with caution
	*/
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetAnimationState(TEnumAsByte<ENpcAnimStatus> newAnimationStatus);

private:

	virtual void SwitchToCombat();

	virtual void SwitchToIdle();

	virtual void SwitchToWander();
	
	virtual void SwitchToDying();

	virtual void SwitchToSpawned();


	virtual void CombatUpdate(float deltaTime);

	virtual void IdleUpdate(float deltaTime);

	virtual void DyingUpdate(float deltaTime);
		
	virtual void SpawnedUpdate(float deltaTime);

	virtual void WanderUpdate(float deltaTime);
	
	UFUNCTION(BlueprintCallable, Category = "State")
	void SwitchAnimation();
	
};
