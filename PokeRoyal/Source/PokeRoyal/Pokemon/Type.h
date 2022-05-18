// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Misc/TVariant.h"
#include "Engine/DataTable.h"
#include "Type.generated.h"



UCLASS(Blueprintable)
class POKEROYAL_API UType : public UObject {
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString tag;

	float efficiency(TArray<UType*> autre);

	bool operator==(UType* autre) {
		return tag == autre->tag;
	}

};


USTRUCT(Blueprintable)
struct FTypeTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UType> type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UType>> ResistAgainst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UType>> WeakAgainst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UType>> NullAgainst;
};


USTRUCT(Blueprintable)
struct FTypeInfo {
	GENERATED_USTRUCT_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UType*> ResistAgainst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UType*> WeakAgainst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UType*> NullAgainst;
};