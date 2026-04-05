// Copyright JKChuong 2026

#pragma once

#include "CoreMinimal.h"

#include "Inv_PlayerController.generated.h"

class UInv_InventoryComponent;
class UInv_HUDWidget;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class INVENTORY_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AInv_PlayerController(); 
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;
private:
	
	void PrimaryInteract();
	void CreateHUDWidget();
	void TraceForItem();
	
	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent; // Weak Ptr since we're adding it in BP instead of contructing it here
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TArray<TObjectPtr<UInputMappingContext>> DefaultIMCs;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction> PrimaryInteractAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction> ToggleInventoryAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TSubclassOf<UInv_HUDWidget> HUDWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> HUDWidget;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	double TraceLength;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;
	
	TWeakObjectPtr<AActor> ThisActor;
	TWeakObjectPtr<AActor> LastActor;
};

