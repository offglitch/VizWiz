// Fill out your copyright notice in the Description page of Project Settings.


#include "VizWizController.h"
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
}

void AVizWizController::BeginPlay()
{
	bBeginPlay = true;
	OnMenuOpening();
	bBeginPlay = false;
}

void AVizWizController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (!InputComponent) return;
	//change in Project Settings -> Input
	InputComponent->BindAction("Menu", IE_Pressed, this, &AVizWizController::OnMenuOpening);
}

void AVizWizController::OnMenuOpening()
{
	//flip flag
	bIsMenuOpened = !bIsMenuOpened;
	if (bIsMenuOpened)
	{
		//show cursor
		SetShowMouseCursor(true);
		//create widget if needed
		if (!WidgetPtr) WidgetPtr = CreateWidget<UVizWizWidget>(this, MenuWidgetClass);
		if (WidgetPtr)
		{
			WidgetPtr->bFirstRun = bBeginPlay;
			//add to viewport and set input mode Game+UI
			WidgetPtr->AddToViewport();
			SetInputMode(FInputModeGameAndUI());
			//binding on clicking out of menu widget
			if (!WidgetPtr->OnCloseClick.IsBoundToObject(this))
				WidgetPtr->OnCloseClick.BindDynamic(this, &AVizWizController::CloseMenuOnNextTick);
			//binding of close button
			if (!bBeginPlay && !WidgetPtr->CloseButton->OnClicked.IsBound())
				WidgetPtr->CloseButton->OnClicked.AddDynamic(this, &AVizWizController::OnMenuOpening);
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

void AVizWizController::CloseMenuOnNextTick()
{
	//delay in 1 tick for completing all the widget logic
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &AVizWizController::OnMenuOpening);
}
