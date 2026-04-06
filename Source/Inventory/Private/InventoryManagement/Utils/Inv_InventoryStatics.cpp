// Copyright JKChuong 2026


#include "InventoryManagement/Utils/Inv_InventoryStatics.h"

#include "InventoryManagement/Components/Inv_InventoryComponent.h"
#include "Items/Components/Inv_ItemComponent.h"

UInv_InventoryComponent* UInv_InventoryStatics::GetInventoryComponent(const APlayerController* PlayerController)
{
	if (PlayerController)
	{
		return PlayerController->FindComponentByClass<UInv_InventoryComponent>();
	}
	
	return nullptr;
}

EInv_ItemCategory UInv_InventoryStatics::GetItemCategoryFromItemComponent(UInv_ItemComponent* ItemComp)
{
	if (ItemComp)
	{
		return ItemComp->GetItemManifest().GetItemCategory();
	}
	
	return EInv_ItemCategory::None;
}
