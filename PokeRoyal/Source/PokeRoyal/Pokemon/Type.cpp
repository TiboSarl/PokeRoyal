// Fill out your copyright notice in the Description page of Project Settings.


#include "PokeRoyal/Pokemon/Type.h"
#include "PokemonRessources.h"

float UType::efficiency(TArray<UType*> autre)
{
	float multiplier = 1;
	auto pokemonRessource = GEngine->GetEngineSubsystem<UPokemonRessources>();
	auto tableType = pokemonRessource->tableType;
	FTypeInfo thisType;
	for (auto autr : autre) {
		thisType.ResistAgainst.Append(tableType[autr->tag].ResistAgainst);
		thisType.WeakAgainst.Append(tableType[autr->tag].WeakAgainst);
		thisType.NullAgainst.Append(tableType[autr->tag].NullAgainst);
	}

	for (auto resistance : thisType.ResistAgainst) {
		if (resistance == this) {
			multiplier *= 0.5;
		}
	}

	for (auto weakness : thisType.WeakAgainst) {
		if (weakness == this) {
			multiplier *= 2;
		}
	}

	for (auto nullify : thisType.WeakAgainst) {
		if (nullify == this) {
			multiplier *= 0;
		}
	}
	return multiplier;
}
