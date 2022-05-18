// Fill out your copyright notice in the Description page of Project Settings.



#include "PokemonRessources.h"
#include "Type.h"

void UPokemonRessources::InitTableType()
{

	const FSoftObjectPath DatabaseLoader = TEXT("DataTable'/Game/Pokemon/Type/TypeTable.TypeTable'");
	UDataTable* Database = Cast<UDataTable>(DatabaseLoader.TryLoad());
	TArray<FTypeTable*> InfoType;
	Database->GetAllRows(TEXT("Getting TypeTable rows"), InfoType);
	for (auto type : InfoType) {
		UObject* o = type->type->GetDefaultObject();
		UClass* c = o->GetClass();
		UType* currentType = NewObject<UType>(this, c);
		tableType.Add(currentType->tag);
		FTypeInfo currentTypeInfo;
		for (auto ResistType : type->ResistAgainst) {
			UObject* o2 = type->type->GetDefaultObject();
			UClass* c2 = o2->GetClass();
			UType* currentResistType = NewObject<UType>(this, c2);
			currentTypeInfo.ResistAgainst.Add(currentResistType);
		}

		for (auto WeakType : type->WeakAgainst) {
			UObject* o2 = type->type->GetDefaultObject();
			UClass* c2 = o2->GetClass();
			UType* currentWeakType = NewObject<UType>(this, c2);
			currentTypeInfo.WeakAgainst.Add(currentWeakType);
		}

		for (auto nullType : type->NullAgainst) {
			UObject* o2 = type->type->GetDefaultObject();
			UClass* c2 = o2->GetClass();
			UType* currentnullType = NewObject<UType>(this, c2);
			currentTypeInfo.NullAgainst.Add(currentnullType);
		}
		tableType[currentType->tag] = currentTypeInfo;
	}

}
