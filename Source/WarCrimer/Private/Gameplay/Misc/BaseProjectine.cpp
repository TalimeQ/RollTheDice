// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Gameplay/Misc/BaseProjectine.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"


// Sets default values
ABaseProjectine::ABaseProjectine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileRepresentation = CreateDefaultSubobject<UPaperFlipbookComponent>("Bullet Representation");
	this->SetRootComponent(projectileRepresentation);
	currentDirection = FVector();
}

// Called when the game starts or when spawned
void ABaseProjectine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	BulletMove(DeltaTime);
}

void ABaseProjectine::SetupBullet(FVector direction, float _travelSpeed, int _damageDealt)
{
	this->currentDirection = direction;
	this->travelSpeed = _travelSpeed;
	this->damageDealt = _damageDealt;
	bIsMoving = true;
}

void ABaseProjectine::SetBulletDirection(FVector newDirection)
{
	this->currentDirection = newDirection;
}

void ABaseProjectine::BulletMove(float DeltaTime)
{
	if (!bIsMoving) return;
	FVector moveOffset = currentDirection * DeltaTime * travelSpeed;
	this->ApplyWorldOffset(moveOffset, false);
}
