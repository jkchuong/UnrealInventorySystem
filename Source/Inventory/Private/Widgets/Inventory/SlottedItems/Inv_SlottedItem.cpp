// Copyright JKChuong 2026


#include "Widgets/Inventory/SlottedItems/Inv_SlottedItem.h"
#include "Items/Inv_InventoryItem.h"

#include "Components/Image.h"

void UInv_SlottedItem::SetImageBrush(const FSlateBrush& SlateBrush) const
{
	Image_Icon->SetBrush(SlateBrush);
}

void UInv_SlottedItem::SetInventoryItem(UInv_InventoryItem* InInventoryItem)
{
	InventoryItem = InInventoryItem;
}
