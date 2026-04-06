// Copyright JKChuong 2026

#pragma once

#include "Inv_GridTypes.generated.h"

class UInv_InventoryItem;

UENUM(BlueprintType)
enum class EInv_ItemCategory : uint8
{
	Equippable,
	Consumable,
	Craftable,
	None
};

USTRUCT()
struct FInv_SlotAvailability
{
	GENERATED_BODY()
	
	FInv_SlotAvailability() {}
	
	FInv_SlotAvailability(const int32 ItemIndex, const int32 Room, const bool bHasItem)
		: Index(ItemIndex)
		, AmountToFill(Room)
		, bItemAtIndex(bHasItem)
	{ }

	/** Index of the slot */
	int32 Index = INDEX_NONE;
	
	/** How many slots to fill */
	int32 AmountToFill = 0;
	
	/** Is there an item at this index */
	bool bItemAtIndex = false;
};

USTRUCT()
struct FInv_SlotAvailabilityResult
{
	GENERATED_BODY()
	
	FInv_SlotAvailabilityResult() {}
	
	/** The item we are triny to fit in the inventory */
	TWeakObjectPtr<UInv_InventoryItem> Item;
	
	/** How many of this item can we fit */
	int32 TotalRoomToFill = 0;
	
	/** How many of this item can we NOT fit */
	int32 Remainder = 0;
	
	/** Is this item stackable */
	bool bStackable = false;
	
	/** Availability of the index we are trying to fill in */
	TArray<FInv_SlotAvailability> SlotAvailabilities;
};