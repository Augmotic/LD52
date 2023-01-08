// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::Damage_Implementation(int32 Amount)
{
	ICombat::Damage_Implementation(Amount);
}

void AEnemyBase::Diffuse_Implementation()
{
	ICombat::Diffuse_Implementation();
}


void AEnemyBase::SetEssence(int32 Value)
{
	Essence = Value;
	CheckEssence();
}

void AEnemyBase::ModifyEssence(int32 Value)
{
	Essence += Value;
	CheckEssence();
}

void AEnemyBase::CheckEssence()
{
	if (Essence > MaxEssence)
	{
		Essence = MaxEssence;
	}
	if (Essence < 0)
	{
		Essence = 0;
	}
	EssenceChangedEvent.Broadcast(Essence);
}
