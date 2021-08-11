// Fill out your copyright notice in the Description page of Project Settings.


#include "VizWizController.h"
#include "IHeadMountedDisplay.h"
#include "IXRTrackingSystem.h"
#include "SpectralPlayer.h"
#include "VizWizWidget.h"
#include "Components/Button.h"

AVizWizController::AVizWizController()
{
	// for simplicity, hardcoded path to the widget (blueprint path has additional "_C")
	ConstructorHelpers::FClassFinder<UVizWizWidget> classFinder(TEXT("/Game/UI/WBP_Menu.WBP_Menu_C"));
	if (classFinder.Succeeded())
	{
		MenuWidgetClass = classFinder.Class;
	}
	//VR checking
	IHeadMountedDisplay *pHmd = nullptr;
	TSharedPtr<IStereoRendering, ESPMode::ThreadSafe> pStereo = nullptr;
	if (GEngine && GEngine->XRSystem) {
		pHmd = GEngine->XRSystem->GetHMDDevice();
		pStereo = GEngine->XRSystem->GetStereoRenderingDevice();
	}
	bVRMode = (pHmd && pStereo && pHmd->IsHMDEnabled() && pHmd->IsHMDConnected() && pStereo->IsStereoEnabled());
	// bVRMode = true; //DEBUGGING
}

ASpectralPlayer* AVizWizController::GetSpectralPlayer()
{
	return ASpectralPlayer::PlayerInstance;
}

void AVizWizController::BeginPlay()
{
	bBeginPlay = true;
	ChangeMenuState();
}

void AVizWizController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!InputComponent) return;
	//change in Project Settings -> Input
	InputComponent->BindAction("Menu", IE_Pressed, this, &AVizWizController::ChangeMenuState);
}

void AVizWizController::ChangeMenuState()
{
	//only song selection to close
	if (bBeginPlay && bIsMenuOpened) return;
	//flip flag
	bIsMenuOpened = !bIsMenuOpened;
	if (!bVRMode) {
		if (bIsMenuOpened)
		{
			//show cursor
			SetShowMouseCursor(true);
			//create widget if needed
			if (!WidgetPtr) WidgetPtr = CreateWidget<UVizWizWidget>(this, MenuWidgetClass);
			if (WidgetPtr)
			{
				if (bBeginPlay) WidgetPtr->bFirstRun = true;
				//add to viewport and set input mode Game+UI
				WidgetPtr->AddToViewport();
				SetInputMode(FInputModeGameAndUI());
				//binding on clicking out of menu widget
				if (!WidgetPtr->OnCloseClick.IsBound())
					WidgetPtr->OnCloseClick.AddDynamic(this, &AVizWizController::CloseMenuOnNextTick);
				//binding of close button
				if (!bBeginPlay && !WidgetPtr->CloseButton->OnClicked.IsBound())
					WidgetPtr->CloseButton->OnClicked.AddDynamic(this, &AVizWizController::ChangeMenuState);
			}
		}
		else
		{
			//hide cursor
			SetShowMouseCursor(false);
			//remove from viewport
			WidgetPtr->RemoveFromViewport();
			//set input mode GameOnly
			SetInputMode(FInputModeGameOnly());
		}
	}
	//Broadcast new state
	OnChangeMenuState.Broadcast(bIsMenuOpened);
}

void AVizWizController::CloseMenuOnNextTick()
{
	bBeginPlay = false;
	//delay in 1 tick for completing all the widget logic
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &AVizWizController::ChangeMenuState);
}
