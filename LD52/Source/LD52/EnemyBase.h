// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ICombat.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"



UCLASS(Abstract)
class LD52_API AEnemyBase : public ACharacter, public ICombat
{
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEssenceChangedEvent, int32, Essence);
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();


	virtual void Damage_Implementation(int32 Amount) override;
	virtual void Diffuse_Implementation() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




protected:
	// Essence
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Essence;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxEssence;
	
	UFUNCTION(BlueprintCallable)
	void SetEssence(int32 Value);
	UFUNCTION(BlueprintCallable)
	void ModifyEssence(int32 Value);
	void CheckEssence();
	UPROPERTY(BlueprintAssignable)
	FEssenceChangedEvent EssenceChangedEvent;
	
};
