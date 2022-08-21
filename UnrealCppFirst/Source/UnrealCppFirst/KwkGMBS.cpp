// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkGMBS.h"
#include"KwkPawn.h"

AKwkGMBS::AKwkGMBS()
{
	// 'AKwakPawn클래스'의 정보를 얻어와서 설정한다
	// 원래 일번적인 cpp에서는 불가능 한 일이다.
	// 여기서는 Pawn이 언리얼 오브젝트이기 때문에 가능하다
	DefaultPawnClass = AKwkPawn::StaticClass();
}