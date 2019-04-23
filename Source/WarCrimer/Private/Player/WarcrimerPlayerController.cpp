// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Player/WarcrimerPlayerController.h"
#include "Public/Player/PlayerAgentCharacter.h"


void AWarcrimerPlayerController::BeginPlay()
{
	Super::BeginPlay();
	this->controlledCharacter = Cast<APlayerAgentCharacter>(GetPawn());
}

void  AWarcrimerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent)
	{
		InputComponent->BindAction(FName("Interact"), EInputEvent::IE_Pressed, this, &AWarcrimerPlayerController::IntentInteract);
		InputComponent->BindAction(FName("Fire"), EInputEvent::IE_Pressed, this, &AWarcrimerPlayerController::IntentShoot);
		InputComponent->BindAxis(FName("Vertical"), this, &AWarcrimerPlayerController::IntentMoveVertical);
		InputComponent->BindAxis(FName("Horizontal"), this, &AWarcrimerPlayerController::IntentMoveHorizontal);
	}
}

void AWarcrimerPlayerController::IntentMoveVertical(float axisValue)
{
	check(controlledCharacter)
	{
		
		controlledCharacter->ProcessIntentMove(axisValue, FVector( 0.0f, -1.0f, 0.0f));
	}
}

void AWarcrimerPlayerController::IntentMoveHorizontal(float axisValue)
{
	check(controlledCharacter)
	{
		
		controlledCharacter->ProcessIntentMove(axisValue, FVector(1.0f, 0.0f, 0.0f));
	}
}

void AWarcrimerPlayerController::IntentInteract()
{
	check(controlledCharacter)
	{
		controlledCharacter->ProcessIntentInteract();
	}
}

void AWarcrimerPlayerController::IntentShoot()
{
	check(controlledCharacter)
	{
		controlledCharacter->ProcessIntentShoot();
	}
}


