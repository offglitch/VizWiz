// Fill out your copyright notice in the Description page of Project Settings.

#include "VizWizWidget_ListItem.h"
#include "VizWizWidget.h"
#include "Components/Button.h"

void UVizWizWidget_ListItem::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ItemButton->OnClicked.AddDynamic(this, &UVizWizWidget_ListItem::OnClick);
}

void UVizWizWidget_ListItem::OnClick()
{
	OnButtonClicked.Broadcast(InternalIndex);
}