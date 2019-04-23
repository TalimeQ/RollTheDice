// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Player/PlayerAgentCharacter.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "Paper2D/Classes/PaperFlipbook.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"


// Sets default values
APlayerAgentCharacter::APlayerAgentCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	playerHitbox = CreateDefaultSubobject<UCapsuleComponent>("Player Hitbox");
}



void APlayerAgentCharacter::MovePawn(float movementValue,FVector Direction)
{
	AddMovementInput(Direction, movementValue);
}

void APlayerAgentCharacter::MoveUp(float movementValue)
{
	fUpMovementValue = movementValue;
}

void APlayerAgentCharacter::MoveRight(float movementValue)
{
	fRightMovementValue = movementValue;
}

// Called when the game starts or when spawned
void APlayerAgentCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerAgentCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerAgentCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//TODO: REFACTOR
void APlayerAgentCharacter::ProcessIntentMove(float value, FVector Direction)
{	
	
	if (Direction == FVector(1.0f, 0.0f, 0.0f))
	{
		MovePawn(value, Direction);
		MoveUp(value);
	}
	else if(Direction == FVector(0.0f, -1.0f, 0.0f))
	{
		MovePawn(value, Direction);
		MoveRight(value);
	}
	if ((fRightMovementValue != 0.0f || fUpMovementValue != 0.0f) && playerAnimationState != EPlayerAnimState::EShooting)
	{
		playerAnimationState = EPlayerAnimState::EWalking;
		ChangeAnimation();
	}
	else if(playerAnimationState != EPlayerAnimState::EShooting)
	{
		playerAnimationState = EPlayerAnimState::EIdle;
		ChangeAnimation();
	}
}


void APlayerAgentCharacter::SetAnimationState(TEnumAsByte<EPlayerAnimState> newState)
{
	playerAnimationState = newState;
}

void APlayerAgentCharacter::ProcessIntentInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting!"));
}

void APlayerAgentCharacter::ChangeAnimation()
{
	UPaperFlipbook** newAnimation = playerAnimSprites.Find(playerAnimationState);
	check(playerRepresentation)
	{
		
		playerRepresentation->SetFlipbook(*newAnimation);
		UE_LOG(LogTemp, Warning, TEXT("Changed Anim"));
	}
}
