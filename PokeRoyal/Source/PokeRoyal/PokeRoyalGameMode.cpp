// Copyright Epic Games, Inc. All Rights Reserved.

#include "PokeRoyalGameMode.h"
#include "PokeRoyalCharacter.h"
#include "Pokemon/PokemonRessources.h"
#include "UObject/ConstructorHelpers.h"

APokeRoyalGameMode::APokeRoyalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APokeRoyalGameMode::InitGame(const FString& MapName,
	const FString& Options,
	FString& ErrorMessage)
{
	Super::InitGame(MapName, Options,ErrorMessage);
	auto pokemonRessource = GEngine->GetEngineSubsystem<UPokemonRessources>();
	pokemonRessource->InitTableType();
}
