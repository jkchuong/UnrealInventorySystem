// Copyright JKChuong 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "Items/Manifest/Inv_ItemManifest.h"

#include "Inv_InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_InventoryItem : public UObject
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsSupportedForNetworking() const override { return true; } // Allows this object to be added to a replicated subobject list
	
	void SetItemManifest(const FInv_ItemManifest& Manifest);
	const FInv_ItemManifest& GetItemManifest() const;
	FInv_ItemManifest& GetItemManifestMutable();

private:
	UPROPERTY(VisibleAnywhere, meta=(BaseStruct = "/Script/Inventory.Inv_ItemManifest"), Replicated, Category = "Inventory")
	FInstancedStruct ItemManifest;
};

template<typename T>
const T* GetFragment(const UInv_InventoryItem* Item, const FGameplayTag& Tag)
{
	if (!IsValid(Item))
	{
		return nullptr;
	}
	
	const FInv_ItemManifest& Manifest = Item->GetItemManifest();
	return Manifest.GetFragmentOfTypeWithTag<T>(Tag);
}