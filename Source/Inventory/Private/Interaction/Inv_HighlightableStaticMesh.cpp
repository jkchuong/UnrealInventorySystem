// Copyright JKChuong 2026


#include "Interaction/Inv_HighlightableStaticMesh.h"

void UInv_HighlightableStaticMesh::Highlight_Implementation()
{
	SetOverlayMaterial(HighlightMaterial);
}

void UInv_HighlightableStaticMesh::Unhighlight_Implementation()
{
	SetOverlayMaterial(nullptr);
}
