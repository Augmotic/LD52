// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ICombat.generated.h"

UINTERFACE(BlueprintType)
class UCombat : public UInterface
{
	GENERATED_BODY()
};

class LD52_API ICombat
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void Damage(int32 Amount);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void Diffuse();
	
};
