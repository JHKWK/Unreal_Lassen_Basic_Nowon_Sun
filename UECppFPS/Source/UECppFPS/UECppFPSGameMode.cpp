// Copyright Epic Games, Inc. All Rights Reserved.

#include "UECppFPSGameMode.h"
#include "UECppFPSHUD.h"
#include "UECppFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUECppFPSGameMode::AUECppFPSGameMode()
	: Super()
{	//CPP수준에서 블루프린트 클래스 정보 얻어오기
	//Blueprint''

	// ConstructorHelpers::FClassFinder를 사용하여  '블루프린트 클래스(에셋)'을 얻어와
	// DefualtPawnClass로 설정 하였다.

	// FClassFinder<T>의 T는 블루프린트 클래스명을 넣는 것이 아니다.
	// 얻고자 하는 블루프린트 클래스의 CPP수준에 존재하는 부모클래스의 타입을 명기해야 한다.

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
		
	HUDClass = AUECppFPSHUD::StaticClass();
}
