// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateGameMode.h"
#include "SlatePlayerController.h"
#include "SlateHUD.h"


ASlateGameMode::ASlateGameMode():Super()
{
	PlayerControllerClass = ASlatePlayerController::StaticClass();
	HUDClass = ASlateHUD::StaticClass();
}