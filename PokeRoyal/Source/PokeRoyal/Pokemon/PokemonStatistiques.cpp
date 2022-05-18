// Fill out your copyright notice in the Description page of Project Settings.


#include "PokeRoyal/Pokemon/PokemonStatistiques.h"

int UPokemonXpCurve::nbExpNeeded_Implementation(int niveau)
{
	return FMath::FloorToInt(0.8 * FMath::Pow(niveau, 3));
}
