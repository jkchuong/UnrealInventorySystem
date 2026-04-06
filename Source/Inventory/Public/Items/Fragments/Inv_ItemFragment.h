// Copyright JKChuong 2026

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Inv_FragmentTags.h"

#include "Inv_ItemFragment.generated.h"

USTRUCT(BlueprintType)
struct FInv_ItemFragment
{
	GENERATED_BODY()
	
	FInv_ItemFragment() { }
	FInv_ItemFragment(const FInv_ItemFragment&) = default;
	FInv_ItemFragment& operator=(const FInv_ItemFragment&) = default;
	FInv_ItemFragment(FInv_ItemFragment&&) = default;
	FInv_ItemFragment& operator=(FInv_ItemFragment&&) = default;
	virtual ~FInv_ItemFragment() { }
	
	FGameplayTag GetFragmentTag() const { return FragmentTag; }
	void SetFragmentTag(const FGameplayTag Tag) { FragmentTag = Tag; }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory", meta=(Categories="Fragments"))
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;
};

USTRUCT(BlueprintType, DisplayName = "Grid Fragment")
struct FInv_GridFragment : public FInv_ItemFragment
{
	GENERATED_BODY()
	
	FInv_GridFragment() { SetFragmentTag(Fragments::GridFragment); }
	
	FIntPoint GetGridSize() const { return GridSize; }
	void SetGridSize(const FIntPoint& Size) { GridSize = Size; }
	float GetGridPadding() const { return GridPadding; }
	void SetGridPadding(const float Padding) { GridPadding = Padding; }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FIntPoint GridSize = FIntPoint(1, 1);
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float GridPadding = 0.f;
};


USTRUCT(BlueprintType, DisplayName = "Image Fragment")
struct FInv_ImageFragment : public FInv_ItemFragment
{
	GENERATED_BODY()
	
	FInv_ImageFragment() { SetFragmentTag(Fragments::ImageFragment); }
	
	UTexture2D* GetIcon() const { return Icon.LoadSynchronous(); }
	
private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSoftObjectPtr<UTexture2D> Icon = nullptr;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FVector2D IconDimensions = FVector2D(44.f, 44.f);
};

