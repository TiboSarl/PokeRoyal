// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Nature.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class POKEROYAL_API UNature : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString tag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DefMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpAttMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpDefMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpeMultiplier;
	
};
