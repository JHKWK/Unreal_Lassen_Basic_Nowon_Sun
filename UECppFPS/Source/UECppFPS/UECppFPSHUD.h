// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UECppFPSHUD.generated.h"

UCLASS()
class AUECppFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUECppFPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	//전방선언
	class UTexture2D* CrosshairTex;

};

