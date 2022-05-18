// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Containers/Map.h"
#include "PokemonStatistiques.generated.h"


/**
 * 
 */
UCLASS()
class POKEROYAL_API UPokemonStatistiques : public UObject
{
	GENERATED_BODY()
public :

	
};

UCLASS(Blueprintable)
class POKEROYAL_API UPokemonXpCurve : public UObject
{
	GENERATED_BODY()
public :

	UFUNCTION(BlueprintNativeEvent)
	int nbExpNeeded(int niveau);
	int nbExpNeeded_Implementation(int niveau);
};




UCLASS(Blueprintable,BlueprintType)
class POKEROYAL_API UPokemonBaseSpecie : public UObject {
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Specimen;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TMap<FString, int> baseStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int expBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UPokemonXpCurve> expCurveClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPokemonXpCurve* xpCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString,int> EvGiven;


};

USTRUCT(BLueprintable)
struct FPokemonSpecieRow : public FTableRowBase {
	
	GENERATED_USTRUCT_BODY()

public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UPokemonBaseSpecie> pokemonBase;
};
