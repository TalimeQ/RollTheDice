// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerAgentCharacter.generated.h"

class UCapsuleComponent;
class UPaperFlipbook;
class UPaperFlipbookComponent;

UENUM(Blueprintable, BlueprintType)
enum EPlayerAnimState
{
	EWalking,
	EIdle,
	EShooting
};

/**
 *
 */

UCLASS()
class WARCRIMER_API APlayerAgentCharacter : public ACharacter
{
	GENERATED_BODY()


protected:

	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly, Category = "Sprite")
	UPaperFlipbookComponent* playerRepresentation = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Collision")
	UCapsuleComponent* playerHitbox = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Sprite")
	TArray<UPaperFlipbook*> playerSprites;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ProcessIntentMoveVertical(float value);

	void ProcessIntentMoveHorizontal(float value);

	void ProcessIntentShoot();

	void ProcessIntentInteract();

	// Sets default values for this character's properties
	APlayerAgentCharacter();
	
private:

	void MoveForward(float movementValue);

	void MoveRight(float movementValue);
};
