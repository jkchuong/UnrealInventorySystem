// Copyright JKChuong 2026


#include "Items/Inv_InventoryItem.h"

#include "Net/UnrealNetwork.h"

void UInv_InventoryItem::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UInv_InventoryItem, ItemManifest);
}

void UInv_InventoryItem::SetItemManifest(const FInv_ItemManifest& Manifest)
{
	ItemManifest = FInstancedStruct::Make<FInv_ItemManifest>(Manifest);
}

const FInv_ItemManifest& UInv_InventoryItem::GetItemManifest() const
{
	return ItemManifest.Get<FInv_ItemManifest>();
}

FInv_ItemManifest& UInv_InventoryItem::GetItemManifestMutable()
{
	return ItemManifest.GetMutable<FInv_ItemManifest>();
}
