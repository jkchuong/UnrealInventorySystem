// Copyright JKChuong 2026


#include "InventoryManagement/Utils/Inv_InventoryStatics.h"

#include "InventoryManagement/Components/Inv_InventoryComponent.h"

UInv_InventoryComponent* UInv_InventoryStatics::GetInventoryComponent(const APlayerController* PlayerController)
{
	if (PlayerController)
	{
		return PlayerController->FindComponentByClass<UInv_InventoryComponent>();
	}
	
	return nullptr;
}
