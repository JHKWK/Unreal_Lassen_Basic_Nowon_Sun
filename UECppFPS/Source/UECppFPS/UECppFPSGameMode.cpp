// Copyright Epic Games, Inc. All Rights Reserved.

#include "UECppFPSGameMode.h"
#include "UECppFPSHUD.h"
#include "UECppFPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUECppFPSGameMode::AUECppFPSGameMode()
	: Super()
{	//CPP���ؿ��� �������Ʈ Ŭ���� ���� ������
	//Blueprint''

	// ConstructorHelpers::FClassFinder�� ����Ͽ�  '�������Ʈ Ŭ����(����)'�� ����
	// DefualtPawnClass�� ���� �Ͽ���.

	// FClassFinder<T>�� T�� �������Ʈ Ŭ�������� �ִ� ���� �ƴϴ�.
	// ����� �ϴ� �������Ʈ Ŭ������ CPP���ؿ� �����ϴ� �θ�Ŭ������ Ÿ���� ����ؾ� �Ѵ�.

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
		
	HUDClass = AUECppFPSHUD::StaticClass();
}
