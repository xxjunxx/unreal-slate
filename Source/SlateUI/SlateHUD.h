// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlateHUD.generated.h"

/**
 * 
 */
UCLASS()
class SLATEUI_API ASlateHUD : public AHUD
{
	GENERATED_BODY()

private:
	bool IsDraw = false;

public:
	
	virtual void DrawHUD() override;
	void DrawStar();
	void SetIsDraw(bool b);
};
