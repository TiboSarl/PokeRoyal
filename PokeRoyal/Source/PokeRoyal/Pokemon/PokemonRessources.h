// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Type.h"
#include "PokemonRessources.generated.h"

/**
 * 
 */
UCLASS()
class POKEROYAL_API UPokemonRessources : public UEngineSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TMap<FString, FTypeInfo> tableType;

	void InitTableType();
	
};
