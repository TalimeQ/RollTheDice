// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectine.generated.h"

class UPaperFlipbookComponent;

UCLASS(abstract)
class  WARCRIMER_API ABaseProjectine : public AActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Bullet")
	FVector currentDirection;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly,Category = "Bullet")
	float travelSpeed = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Bullet")
	int DamageDealt = 1;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Bullet")
	UPaperFlipbookComponent* projectileRepresentation;

public:	
	// Sets default values for this actor's properties
	ABaseProjectine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	virtual void OnInteraction(AActor* interactedActor) PURE_VIRTUAL(ABaseProjectine::OnInteraction, ;);
	
};
