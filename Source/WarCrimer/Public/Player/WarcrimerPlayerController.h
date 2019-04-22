// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WarcrimerPlayerController.generated.h"


class APlayerAgentCharacter;

/**
 * 
 */
UCLASS()
class WARCRIMER_API AWarcrimerPlayerController : public APlayerController
{
	GENERATED_BODY()



protected:
	 void SetupInputComponent() override;
private:
	void BeginPlay() override;
	void IntentMoveVertical(float axisValue);
	void IntentMoveHorizontal(float axisValue);
	void IntentInteract();
	void IntentShoot();

private:
	APlayerAgentCharacter* controlledCharacter = nullptr;

};
