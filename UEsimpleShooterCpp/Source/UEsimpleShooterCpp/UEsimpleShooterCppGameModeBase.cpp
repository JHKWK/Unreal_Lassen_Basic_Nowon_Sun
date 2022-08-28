// Copyright Epic Games, Inc. All Rights Reserved.


#include "UEsimpleShooterCppGameModeBase.h"
#include "KwkPawn.h"

AUEsimpleShooterCppGameModeBase::AUEsimpleShooterCppGameModeBase()
{
	UE_LOG(LogTemp, Log, TEXT("AUEsimpleShooterCppGameModeBase::AUEsimpleShooterCppGameModeBase"));

	DefaultPawnClass = AKwkPawn::StaticClass();
}