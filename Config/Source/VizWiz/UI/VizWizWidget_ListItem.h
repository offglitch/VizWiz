// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VizWizWidget_ListItem.generated.h"

UCLASS()
class VIZWIZ_API UVizWizWidget_ListItem : public UUserWidget
{
	GENERATED_BODY()

public:
	//Widget elements
	UPROPERTY(meta = (BindWidget))
	class UButton* ItemButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemText;

	// Called when the button is clicked
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClicked, int32, ButtonIndex);
	UPROPERTY(BlueprintAssignable)
	FOnButtonClicked OnButtonClicked;

public:
	//setter
	void SetInternalIndex(const int32 NewInternalIndex) { InternalIndex = NewInternalIndex; }

protected:
	//index of list item
	int32 InternalIndex;

protected:
	//exec only once on initialization
	virtual void NativeOnInitialized() override;

	//Button click
	UFUNCTION()
	void OnClick();
};
