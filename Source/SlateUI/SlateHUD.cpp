// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateHUD.h"

#include "CanvasItem.h"
#include "SCanvas.h"
#include "Engine.h"
#include "Math.h"


void ASlateHUD::DrawHUD()
{
	Super::DrawHUD();
	
	if (IsDraw)
	{
		DrawStar();
	}
}

void ASlateHUD::DrawStar()
{	
	float StartAngle = -PI /2;
	float Radius = 150.0f;
	float Dig = (2 * PI / 5) * 2;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	FVector2D Center = FVector2D(ViewportSize.X / 2, 200);
	FVector2D PrePoint = FVector2D(Center.X, Center.Y - Radius);
	for (int32 i = 0; i < 6; i++) 
	{
		float x = Center.X + cos(StartAngle + Dig * i) * Radius;
		float y = Center.Y + sin(StartAngle + Dig * i) * Radius;
		FCanvasLineItem NewLine(PrePoint, FVector2D(x, y));
		Canvas->DrawItem(NewLine);
		PrePoint = FVector2D(x, y);
	}
}

void ASlateHUD::SetIsDraw(bool b)
{ 
	IsDraw = b;
}
