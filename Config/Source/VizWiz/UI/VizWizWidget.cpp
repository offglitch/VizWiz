// Fill out your copyright notice in the Description page of Project Settings.


#include "VizWizWidget.h"
#include "SpectralPlayer.h"
#include "VizWizController.h"
#include "VizWizWidget_ListItem.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

UVizWizWidget::UVizWizWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ItemColor(FSlateColor(FLinearColor::White))
	, SelectedColor(FSlateColor(FLinearColor::Green))
	, ItemIndex(0)
{}

void UVizWizWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//Delegates binding
	Border_In->OnMouseButtonDownEvent.BindDynamic(this, &UVizWizWidget::BorderClickIn);
	Border_Out->OnMouseButtonDownEvent.BindDynamic(this, &UVizWizWidget::BorderClickOut);
}

void UVizWizWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateList();
}


void UVizWizWidget::UpdateList()
{
	//Clearing lists just in case
	ItemList.Empty();
	SongList->ClearChildren();
	//get clips and index
	const auto& clips = ASpectralPlayer::PlayerInstance->GetTimeSynthClips();
	ItemIndex = ASpectralPlayer::PlayerInstance->GetCurrentClipIndex();
	//and iterate through
	for (int32 i = 0; i < clips.Num(); ++i)
	{
		// identify the name by the first SoundWave in the TimeSynthClip
		ItemList.Add(clips[i]->Sounds[0].SoundWave->GetName());
		// creating a new widget
		UVizWizWidget_ListItem* newWidget = CreateWidget<UVizWizWidget_ListItem>(GetOwningPlayer(), ItemListWidget);
		// adding it to the list widget
		const auto panelSlot = SongList->AddChild(newWidget);
		// take the desired widget
		const auto item = Cast<UVizWizWidget_ListItem>(panelSlot->Content);
		// and set text, text color, focus, internal index and delegate binding
		item->ItemText->SetText(FText::FromString(ItemList.Last()));
		item->ItemText->SetColorAndOpacity(i == ItemIndex ? SelectedColor : ItemColor);
		item->ItemButton->SetFocus();
		item->SetInternalIndex(i);
		item->OnButtonClicked.AddDynamic(this, &UVizWizWidget::ChangeClip);
	}
	//Get selected song
	auto child = SongList->GetChildAt(ItemIndex);
	//Scroll to selected song
	SongList->ScrollWidgetIntoView(child, false);
}

void UVizWizWidget::ChangeClip(int32 NewClipIndex)
{
	//if the new index differs
	if (ItemIndex != NewClipIndex)
	{
		if (ItemIndex > 0 && ItemIndex < ItemList.Num())
		{
			//take current item and set color
			const auto curItem = Cast<UVizWizWidget_ListItem>(SongList->GetChildAt(ItemIndex));
			curItem->ItemText->SetColorAndOpacity(ItemColor);
		}
		//take new item, set color
		const auto newItem = Cast<UVizWizWidget_ListItem>(SongList->GetChildAt(NewClipIndex));
		newItem->ItemText->SetColorAndOpacity(SelectedColor);
		//Сalling for player playback
		ASpectralPlayer::PlayerInstance->Play(NewClipIndex);
		if (ItemIndex < 0 && bFirstRun) OnCloseClick.ExecuteIfBound();
		ItemIndex = NewClipIndex;
	}
}

void UVizWizWidget::PlayButtonClick()
{
	ASpectralPlayer::PlayerInstance->Play(ItemIndex);
}

FEventReply UVizWizWidget::BorderClickIn(FGeometry MyGeometry, const FPointerEvent& MouseEvent)
{
	//Return the Handled Reply to prevent it being triggered on the outer Border
	FEventReply Reply;
	Reply.NativeReply = FReply::Handled();
	return Reply;
}

FEventReply UVizWizWidget::BorderClickOut(FGeometry MyGeometry, const FPointerEvent& MouseEvent)
{
	//Execute delegate and return handled reply
	if(!bFirstRun) OnCloseClick.ExecuteIfBound();
	FEventReply Reply;
	Reply.NativeReply = FReply::Handled();
	return Reply;
}