// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkGMBS.h"
#include"KwkPawn.h"

AKwkGMBS::AKwkGMBS()
{
	// 'AKwakPawnŬ����'�� ������ ���ͼ� �����Ѵ�
	// ���� �Ϲ����� cpp������ �Ұ��� �� ���̴�.
	// ���⼭�� Pawn�� �𸮾� ������Ʈ�̱� ������ �����ϴ�
	DefaultPawnClass = AKwkPawn::StaticClass();
}