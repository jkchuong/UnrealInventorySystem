// Copyright JKChuong 2026

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"


class UInv_InventoryBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInv_InventoryComponent();

	void ToggleInventoryMenu();
	
protected:
	virtual void BeginPlay() override;
	
private:
	void ConstructInventory();
	
	TWeakObjectPtr<APlayerController> OwningController;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_InventoryBase> InventoryMenuClass;
	
	UPROPERTY()
	TObjectPtr<UInv_InventoryBase> InventoryMenu;
	
	bool bInventoryMenuOpen = false;
	void OpenInventoryMenu();
	void CloseInventoryMenu();
};
