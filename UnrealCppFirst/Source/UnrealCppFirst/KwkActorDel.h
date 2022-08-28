// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KwkActorDel.generated.h"

// Unreal의 deligate 문법을 살펴보자
//
//	간접호출도구로서의 객체를 만들 수 있는 타입이다
//	언리얼 매크로로 선언하여 만든다
//
//	델리게이트 이름은 F로 시작한다.
//	(그렇지 않으면 오류가 날 가능성이 있다)
// 
//Single Cast Delegate                        Multi Cast Delegate
//
// BindFunction              --->            AddUFuntion
// Excute                    --->            Broadcast
// Unbind                    --->            Clear
// 
// 
//델리게이트 선언 이름은 FDeleVoid
DECLARE_DELEGATE(FDeleVoid);
DECLARE_DELEGATE_TwoParams(FDeleTwoParam, int, int);
DECLARE_DELEGATE_RetVal_TwoParams(int, FDeleRetValTwoParam, int, int);

//multi cast delegate
//여러개의 함수를 등록하여 동시에 호출 가능하다
DECLARE_MULTICAST_DELEGATE_TwoParams(FDeleTwoParamMuli, int, int);

//dynamic multi cast delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeleVoidMultiDynamic);




UCLASS()
class UNREALCPPFIRST_API AKwkActorDel : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	AKwkActorDel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	FDeleVoid mFuncVoid;
	FDeleTwoParam mFuncTwoParam;
	FDeleRetValTwoParam mFuncRetValTwoParam;
	FDeleTwoParamMuli mFuncTwoParamMulti;
	FDeleVoidMultiDynamic mDeleVoidMultiDynamic;

public:
	//매개변수가 없는 함수이다 언리얼 매크로를 적용해 주어 언리얼 엔진의 관리하에 있게 하자
	UFUNCTION()
	void Doit();

	UFUNCTION()
		void DoAdd(int tA, int tB);

	UFUNCTION()
		void DoDivide(int tA, int tB);

	UFUNCTION()
		int DoMultiply(int tA, int tB);


public:
	/*
		이벤트 모델 원리에 의해 간접호출 도구가 만들어진 형식이다
		해당 클래스에 종속된 형태로 사용한다
		사용법은 multi cast delegate와 동일하다
	*/

	DECLARE_EVENT(AKwkActorDel, FEventVoid);
	FEventVoid mEventVoid;
};
