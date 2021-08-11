// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "VizWizWidget_ListItem.h"
#include "Blueprint/UserWidget.h"
#include "VizWizWidget.generated.h"

UCLASS()
class VIZWIZ_API UVizWizWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBorderClicked);
	UPROPERTY(BlueprintAssignable)
	FOnBorderClicked OnCloseClick;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UButton* CloseButton;

	UPROPERTY(BlueprintReadWrite)
	bool bFirstRun = false;

public:
	//widget constructor requires argumented parent constructor
	UVizWizWidget(const FObjectInitializer& ObjectInitializer);

protected:
	//class of subwidget
	UPROPERTY(EditAnywhere, Category = "List", BlueprintReadOnly)
	TSubclassOf<UVizWizWidget_ListItem> ItemListWidget;

	//default item color
	UPROPERTY(EditAnywhere, Category = "List", BlueprintReadWrite)
	FSlateColor ItemColor;

	//selected item color
	UPROPERTY(EditAnywhere, Category = "List", BlueprintReadWrite)
	FSlateColor SelectedColor;

	//widget with the same name will be bound to variable
	UPROPERTY(meta = (BindWidget))
	class UBorder* Border_Out;

	UPROPERTY(meta = (BindWidget))
	class UBorder* Border_In;

	UPROPERTY(meta = (BindWidget))
	class UScrollBox* SongList;

	//Array for list
	UPROPERTY(BlueprintReadOnly)
	TArray<FString> ItemList;

	//selected item index
	UPROPERTY(BlueprintReadWrite)
	int32 ItemIndex;

protected:
	//exec only once on initialization
	virtual void NativeOnInitialized() override;
	//needs for ScrollBox, because during NativeOnInitialized() there is no widget geometry cache
	virtual void NativeConstruct() override;

	//updating list
	void UpdateList();

	//changing song
	UFUNCTION()
	void ChangeClip(int32 NewClipIndex);

	UFUNCTION()
	void PlayButtonClick();

	UFUNCTION()
	FEventReply BorderClickIn(FGeometry MyGeometry, const FPointerEvent& MouseEvent);

	UFUNCTION()
	FEventReply BorderClickOut(FGeometry MyGeometry, const FPointerEvent& MouseEvent);

};
