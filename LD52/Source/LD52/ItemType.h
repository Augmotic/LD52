#pragma once

#include "CoreMinimal.h"
#include "ItemType.generated.h"

UENUM(BlueprintType)
enum class EEquipmentType : uint8 {
	Pistol		UMETA(DisplayName="Pistol"),
	Detection	UMETA(DisplayName="Detection"),
	Diffuse		UMETA(DisplayName="Diffuse"),
	Conceal		UMETA(DisplayName="Conceal"),
};