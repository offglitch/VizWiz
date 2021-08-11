// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "VizWizWidget.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"
#include "GameFramework/PlayerController.h"
#include "VizWizController.generated.h"

UCLASS()
class VIZWIZ_API AVizWizController : public APlayerController
{
	GENERATED_BODY()
public:
	AVizWizController();

protected:
	//class of menu widget
	TSubclassOf<UVizWizWidget> MenuWidgetClass;
	//flag of opened menu
	bool bIsMenuOpened = false;
	//flag of beginning
	bool bBeginPlay = true;
	//widget ptr
	UPROPERTY()
	UVizWizWidget* WidgetPtr = nullptr;

protected:
	virtual void BeginPlay() override;
	//input setup
	virtual void SetupInputComponent() override;

private:
	UFUNCTION()
	void OnMenuOpening();

	UFUNCTION()
	void CloseMenuOnNextTick();
};
