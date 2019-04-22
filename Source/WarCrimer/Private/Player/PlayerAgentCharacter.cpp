// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Player/PlayerAgentCharacter.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"


// Sets default values
APlayerAgentCharacter::APlayerAgentCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	playerRepresentation = CreateDefaultSubobject<UPaperFlipbookComponent>("Player Flipbook");
	playerHitbox = CreateDefaultSubobject<UCapsuleComponent>("Player Hitbox");
}

void APlayerAgentCharacter::MoveForward(float movementValue)
{
	FVector Direction = FVector(1, 0, 0);
	AddMovementInput(Direction, movementValue);
}

void APlayerAgentCharacter::MoveRight(float movementValue)
{
	FVector Direction = FVector(0, 1, 0);
	AddMovementInput(Direction, movementValue);
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

void APlayerAgentCharacter::ProcessIntentMoveVertical(float value)
{
	if (value != 0.0)
	{
		MoveForward(value);
		UE_LOG(LogTemp, Warning, TEXT("FORWARD!"));
	}
	
	
}

void APlayerAgentCharacter::ProcessIntentMoveHorizontal(float value)
{	
	if (value != 0.0)
	{
		MoveRight(value);
		UE_LOG(LogTemp, Warning, TEXT("Right!"));
	}
	
}

void APlayerAgentCharacter::ProcessIntentShoot()
{
	UE_LOG(LogTemp, Warning, TEXT("Shooting!"));
}

void APlayerAgentCharacter::ProcessIntentInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting!"));
}

