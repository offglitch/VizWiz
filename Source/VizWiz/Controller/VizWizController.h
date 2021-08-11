// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "VizWizWidget.h"
#include "GameFramework/PlayerController.h"
#include "VizWizController.generated.h"

UCLASS()
class VIZWIZ_API AVizWizController : public APlayerController
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangingMenuState, bool, NewMenuState);
	UPROPERTY(BlueprintAssignable)
	FOnChangingMenuState OnChangeMenuState;

	//flag of beginning
	UPROPERTY(BlueprintReadOnly)
	bool bBeginPlay;

public:
	AVizWizController();

	UFUNCTION(BlueprintCallable)
	void ChangeMenuState();

	UFUNCTION(BlueprintCallable)
	class ASpectralPlayer* GetSpectralPlayer();

	UFUNCTION(BlueprintCallable)
	void CloseMenuOnNextTick();

protected:
	//class of menu widget
	TSubclassOf<UVizWizWidget> MenuWidgetClass;
	//widget ptr
	UPROPERTY()
	UVizWizWidget* WidgetPtr = nullptr;
	//Virtual Reality flag
	bool bVRMode;

	//flag of opened menu
	bool bIsMenuOpened = false;

protected:
	virtual void BeginPlay() override;
	//input setup
	virtual void SetupInputComponent() override;
};
