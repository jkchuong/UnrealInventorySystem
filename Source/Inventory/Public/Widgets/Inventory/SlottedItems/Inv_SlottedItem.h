// Copyright JKChuong 2026

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_SlottedItem.generated.h"

class UInv_InventoryItem;
class UImage;
/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_SlottedItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetIsStackable(const bool bInIsStackable) { bIsStackable = bInIsStackable; }
	bool GetIsStackable() const { return bIsStackable; }
	
	void SetImageBrush(const FSlateBrush& SlateBrush) const;
	UImage* GetImageIcon() const { return Image_Icon; }
	
	void SetGridIndex(const int32 Index) { GridIndex = Index; }
	int32 GetGridIndex() const { return GridIndex; }
	
	void SetGridDimensions(const FIntPoint& Dimensions) { GridDimensions = Dimensions; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	
	void SetInventoryItem(UInv_InventoryItem* InInventoryItem);
	UInv_InventoryItem* GetInventoryItem() const { return InventoryItem.Get(); }
	
private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> Image_Icon;
	
	int32 GridIndex;
	FIntPoint GridDimensions;
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	bool bIsStackable = false;
};
