// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ICombat.h"
#include "InputActionValue.h"
#include "ItemType.h"
#include "GameFramework/Character.h"
#include "PlayerCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEssenceChangedEvent, int32, Essence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAmmoChangedEvent, int32, Ammo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMagazineChangedEvent, int32, Magazine);

UCLASS(Abstract)
class LD52_API APlayerCharacterBase : public ACharacter, public ICombat
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	
public:
	// Sets default values for this character's properties
	APlayerCharacterBase();

	virtual void Damage_Implementation(int32 Amount) override;
	virtual void Diffuse_Implementation() override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	// Magazine
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Magazine;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxMagazine;
	UFUNCTION(BlueprintCallable)
	void SetMagazine(int32 Value);
	UFUNCTION(BlueprintCallable)
	void ModifyMagazine(int32 Value);
	void CheckMagazine();
	UPROPERTY(BlueprintAssignable)
	FMagazineChangedEvent MagazineChangedEvent;
	
	// Ammo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Ammo;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxAmmo;
	UFUNCTION(BlueprintCallable)
	void SetAmmo(int32 Value);
	UFUNCTION(BlueprintCallable)
	void ModifyAmmo(int32 Value);
	void CheckAmmo();
	UPROPERTY(BlueprintAssignable)
	FAmmoChangedEvent AmmoChangedEvent;




	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EEquipmentType SelectedEquipment;
	

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
};
