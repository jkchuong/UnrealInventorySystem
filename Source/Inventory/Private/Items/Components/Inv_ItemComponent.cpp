// Copyright JKChuong 2026


#include "Items/Components/Inv_ItemComponent.h"

UInv_ItemComponent::UInv_ItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PickupMessage = FString ("E - Pick Up");
}