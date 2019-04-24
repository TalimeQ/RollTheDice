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
		float travelSpeed { 100.0f };

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Bullet")
		int damageDealt{ 1 };

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Bullet")
		UPaperFlipbookComponent* projectileRepresentation;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Bullet")
		bool bIsMoving = true;

public:	
	// Sets default values for this actor's properties
	ABaseProjectine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	virtual void SetupBullet(FVector direction, float _travelSpeed, int _damageDealt);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBulletDirection(FVector newDirection);

private:

	virtual void OnInteraction(AActor* interactedActor) PURE_VIRTUAL(ABaseProjectine::OnInteraction, ;);
	
	virtual void BulletMove(float DeltaTime);
};
