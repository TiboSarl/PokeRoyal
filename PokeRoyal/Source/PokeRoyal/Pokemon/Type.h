// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/TVariant.h"
#include "Type.generated.h"


USTRUCT(BlueprintType)
struct FPokemonType
{
	GENERATED_USTRUCT_BODY()
};

USTRUCT(BlueprintType)
struct FFireType : public FPokemonType
{
	GENERATED_USTRUCT_BODY()
};

USTRUCT(BlueprintType)
struct FWaterType : public FPokemonType
{
	GENERATED_USTRUCT_BODY()
};

USTRUCT(BlueprintType)
struct FGrassType : public FPokemonType
{
	GENERATED_USTRUCT_BODY()
};


using TypeVariant = TVariant<FGrassType, FWaterType, FFireType>;

USTRUCT()
struct FTypeVisitor
{
	GENERATED_USTRUCT_BODY()

		//Type feu
		float operator() (FFireType, FGrassType) { return 2; }
		float operator() (FFireType, FWaterType) { return 0.5; }
		float operator() (FFireType, FFireType) { return 0.5; }


		//Type eau
		float operator() (FWaterType, FGrassType) { return 0.5; }
		float operator() (FWaterType, FWaterType) { return 0.5; }
		float operator() (FWaterType, FFireType) { return 2; }

		//Type plante
		float operator() (FGrassType, FGrassType) { return 0.5; }
		float operator() (FGrassType, FWaterType) { return 2; }
		float operator() (FGrassType, FFireType) { return 0.5; }
};

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class POKEROYAL_API UType : public UObject
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPokemonType pokemonType;


	
	
};
