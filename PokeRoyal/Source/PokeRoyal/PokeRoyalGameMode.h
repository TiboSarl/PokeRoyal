// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PokeRoyalGameMode.generated.h"

UCLASS(minimalapi)
class APokeRoyalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APokeRoyalGameMode();

	void InitGame(const FString& MapName,
		const FString& Options,
		FString& ErrorMessage) override;
};



