// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SlateBasics.h"
#include "SButton.h"
#include "STextBlock.h"
#include "Engine.h"
#include "SlatePlayerController.generated.h"


/**
 * 
 */
UCLASS()
class SLATEUI_API ASlatePlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	bool isButtonShow = false;
	bool isButtonClicked = false;
	TSharedPtr<SVerticalBox> Widget;
	TSharedPtr<STextBlock> ButtonLabel;

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	void onButtonShow();
	FReply ButtonClicked();
	void DrawTrajectory(bool IsDraw);
};
