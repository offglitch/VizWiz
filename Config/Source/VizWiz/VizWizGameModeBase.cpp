// Copyright Epic Games, Inc. All Rights Reserved.


#include "VizWizGameModeBase.h"

#include "VizWizController.h"

AVizWizGameModeBase::AVizWizGameModeBase()
{
	PlayerControllerClass = AVizWizController::StaticClass();
}
