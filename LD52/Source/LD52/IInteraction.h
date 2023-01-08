// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteraction.generated.h"

UINTERFACE(BlueprintType)
class UInteraction : public UInterface
{
	GENERATED_BODY()
};

class LD52_API IInteraction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void Interact(AActor* Source);
	
};
