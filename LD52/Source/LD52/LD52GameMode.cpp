// Copyright Epic Games, Inc. All Rights Reserved.

#include "LD52GameMode.h"
#include "LD52Character.h"
#include "UObject/ConstructorHelpers.h"

ALD52GameMode::ALD52GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
