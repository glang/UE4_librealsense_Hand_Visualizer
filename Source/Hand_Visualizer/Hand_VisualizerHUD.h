// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "Hand_VisualizerHUD.generated.h"

UCLASS()
class AHand_VisualizerHUD : public AHUD
{
	GENERATED_BODY()

public:
	AHand_VisualizerHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

