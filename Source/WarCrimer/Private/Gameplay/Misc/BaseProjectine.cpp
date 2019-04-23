// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Gameplay/Misc/BaseProjectine.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"


// Sets default values
ABaseProjectine::ABaseProjectine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileRepresentation = CreateDefaultSubobject<UPaperFlipbookComponent>("Bullet Representation");
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

}

