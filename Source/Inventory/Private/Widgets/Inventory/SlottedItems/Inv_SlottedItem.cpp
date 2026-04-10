// Copyright JKChuong 2026


#include "Widgets/Inventory/SlottedItems/Inv_SlottedItem.h"
#include "Items/Inv_InventoryItem.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"

void UInv_SlottedItem::SetImageBrush(const FSlateBrush& SlateBrush) const
{
	Image_Icon->SetBrush(SlateBrush);
}

void UInv_SlottedItem::SetInventoryItem(UInv_InventoryItem* InInventoryItem)
{
	InventoryItem = InInventoryItem;
}

void UInv_SlottedItem::UpdateStackCount(int32 StackCount)
{
	if (StackCount > 0)
	{
		Text_StackCount->SetText(FText::AsNumber(StackCount));
		Text_StackCount->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	else
	{
		Text_StackCount->SetVisibility(ESlateVisibility::Collapsed);
	}
}
