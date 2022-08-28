// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KwkActorDel.generated.h"

// Unreal�� deligate ������ ���캸��
//
//	����ȣ�⵵���μ��� ��ü�� ���� �� �ִ� Ÿ���̴�
//	�𸮾� ��ũ�η� �����Ͽ� �����
//
//	��������Ʈ �̸��� F�� �����Ѵ�.
//	(�׷��� ������ ������ �� ���ɼ��� �ִ�)
// 
//Single Cast Delegate                        Multi Cast Delegate
//
// BindFunction              --->            AddUFuntion
// Excute                    --->            Broadcast
// Unbind                    --->            Clear
// 
// 
//��������Ʈ ���� �̸��� FDeleVoid
DECLARE_DELEGATE(FDeleVoid);
DECLARE_DELEGATE_TwoParams(FDeleTwoParam, int, int);
DECLARE_DELEGATE_RetVal_TwoParams(int, FDeleRetValTwoParam, int, int);

//multi cast delegate
//�������� �Լ��� ����Ͽ� ���ÿ� ȣ�� �����ϴ�
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
	//�Ű������� ���� �Լ��̴� �𸮾� ��ũ�θ� ������ �־� �𸮾� ������ �����Ͽ� �ְ� ����
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
		�̺�Ʈ �� ������ ���� ����ȣ�� ������ ������� �����̴�
		�ش� Ŭ������ ���ӵ� ���·� ����Ѵ�
		������ multi cast delegate�� �����ϴ�
	*/

	DECLARE_EVENT(AKwkActorDel, FEventVoid);
	FEventVoid mEventVoid;
};
