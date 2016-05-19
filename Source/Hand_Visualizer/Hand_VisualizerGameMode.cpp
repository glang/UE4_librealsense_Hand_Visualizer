// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Hand_Visualizer.h"
#include "Hand_VisualizerGameMode.h"
#include "Hand_VisualizerHUD.h"
#include "Hand_VisualizerCharacter.h"

AHand_VisualizerGameMode::AHand_VisualizerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHand_VisualizerHUD::StaticClass();
}
