// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterBase.h"

#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacterBase::APlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(RootComponent, USpringArmComponent::SocketName); 

	
}

// Called when the game starts or when spawned
void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
}

// Called every frame
void APlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void APlayerCharacterBase::Damage_Implementation(int32 Amount)
{
	ICombat::Damage_Implementation(Amount);
}

void APlayerCharacterBase::Diffuse_Implementation()
{
	ICombat::Diffuse_Implementation();
}


// Essence
void APlayerCharacterBase::SetEssence(int32 Value)
{
	Essence = Value;
	CheckEssence();
}
void APlayerCharacterBase::ModifyEssence(int32 Value)
{
	Essence += Value;
	CheckEssence();
}
void APlayerCharacterBase::CheckEssence()
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

// Magazine
void APlayerCharacterBase::SetMagazine(int32 Value)
{
	Magazine = Value;
	CheckMagazine();
}
void APlayerCharacterBase::ModifyMagazine(int32 Value)
{
	Magazine += Value;
	CheckMagazine();
}
void APlayerCharacterBase::CheckMagazine()
{
	if (Magazine > MaxMagazine)
	{
		Magazine = MaxMagazine;
	}
	if (Magazine < 0)
	{
		Magazine = 0;
	}
	MagazineChangedEvent.Broadcast(Magazine);
}

// Ammo
void APlayerCharacterBase::SetAmmo(int32 Value)
{
	Ammo = Value;
	CheckAmmo();
}
void APlayerCharacterBase::ModifyAmmo(int32 Value)
{
	Ammo += Value;
	CheckAmmo();
}
void APlayerCharacterBase::CheckAmmo()
{
	if (Ammo > MaxAmmo)
	{
		Ammo = MaxAmmo;
	}
	if (Ammo < 0)
	{
		Ammo = 0;
	}
	AmmoChangedEvent.Broadcast(Ammo);
}
