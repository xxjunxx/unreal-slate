// Fill out your copyright notice in the Description page of Project Settings.

#include "SlatePlayerController.h"
#include "SlateHUD.h"

void ASlatePlayerController::BeginPlay()
{

	Widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ASlatePlayerController::ButtonClicked))
			.Content()
			[
				SAssignNew(ButtonLabel, STextBlock)
				.Font(FSlateFontInfo(FPaths::EngineContentDir() / TEXT("Slate/Fonts/Roboto-Bold.ttf"), 32))
				.Text(FText::FromString(TEXT("Show Trajectory")))
			]
		];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), Widget.ToSharedRef(), 1);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	this->Widget.ToSharedRef()->SetVisibility(EVisibility::Hidden);
}


void ASlatePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("ShowButton", IE_Pressed, this, &ASlatePlayerController::onButtonShow);
}

void ASlatePlayerController::onButtonShow()
{
	if (!isButtonShow)
	{
		this->Widget.ToSharedRef()->SetVisibility(EVisibility::Visible);
		isButtonShow = true;
	}
	else {
		this->Widget.ToSharedRef()->SetVisibility(EVisibility::Hidden);
		isButtonShow = false;
	}
}

FReply ASlatePlayerController::ButtonClicked()
{	

	if (!isButtonClicked)
	{
		ButtonLabel->SetText(FString(TEXT("Disapper")));
		isButtonClicked = true;
		DrawTrajectory(true);
	}
	else {
		ButtonLabel->SetText(FString(TEXT("Show Trajectory")));
		isButtonClicked = false;
		DrawTrajectory(false);
	}
	
	return FReply::Handled();
}

void ASlatePlayerController::DrawTrajectory(bool IsDraw)
{
	ASlateHUD* c = Cast<ASlateHUD>(GetHUD());
	c->SetIsDraw(IsDraw);
} 