// Fill out your copyright notice in the Description page of Project Settings.


#include  "KwkActorDel.h"

// Sets default values
AKwkActorDel::AKwkActorDel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//	Fstring : �Ϲ����� ���ڿ�
//	FText   : ����ȭ�� �ؽ�Ʈ ����� �����ϴ� ���ڿ�
//	FName   : �˻��� ���ڿ�

// Called when the game starts or when spawned
void AKwkActorDel::BeginPlay()
{
	Super::BeginPlay();
	
	//��������Ʈ�� �Լ� ����
	mFuncVoid.BindUFunction(this, FName("Doit"));

	//������ ��ȿ���� �˻�
	if (mFuncVoid.IsBound())
	{
		//��������Ʈ�� �Լ� ����ȣ��
		mFuncVoid.Execute();
	}

	mFuncTwoParam.BindUFunction(this, FName("DoAdd"));
	if (mFuncTwoParam.IsBound())
	{
		mFuncTwoParam.Execute(2,3);
	}

	mFuncRetValTwoParam.BindUFunction(this, FName("DoMultiply"));
	if (mFuncRetValTwoParam.IsBound())
	{
		mFuncRetValTwoParam.Execute(2, 3);
	}

	mFuncTwoParamMulti.AddUFunction(this, FName("DoAdd"));
	mFuncTwoParamMulti.AddUFunction(this, FName("DoDivide"));
	if (mFuncTwoParamMulti.IsBound())
	{
		mFuncTwoParamMulti.Broadcast(2, 3);
	}

	//Event
	mEventVoid.AddUFunction(this, FName("Doit"));
	if (mEventVoid.IsBound())
	{
		UE_LOG(LogTemp, Warning, TEXT("===Doit===!!"))
		mEventVoid.Broadcast();
	}

	//Dynamic multi cast delgate
	mDeleVoidMultiDynamic.AddDynamic(this, &AKwkActorDel::Doit);
	if (mDeleVoidMultiDynamic.IsBound())
	{
		UE_LOG(LogTemp, Warning, TEXT("===Doit===!!"))
			mDeleVoidMultiDynamic.Broadcast();
	}

}

void AKwkActorDel::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//��������Ʈ ��ü �������� ������ ����

	mFuncVoid.Unbind();
	mFuncTwoParam.Unbind();
	mFuncRetValTwoParam.Unbind();
	mFuncTwoParamMulti.Clear();
	mEventVoid.Clear();
	mDeleVoidMultiDynamic.Clear();

}

// Called every frame
void AKwkActorDel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKwkActorDel::Doit()
{
	UE_LOG(LogTemp, Warning, TEXT("===Doit==="));
}

void AKwkActorDel::DoAdd(int tA, int tB)
{
	int tR = tA + tB;
	UE_LOG(LogTemp, Warning, TEXT("DoAdd: %d"), tR);
}

void AKwkActorDel::DoDivide(int tA, int tB)
{
	float tR = (float)tA / (float)tB;
	UE_LOG(LogTemp, Warning, TEXT("DoDivide: %f"), tR);
}

int AKwkActorDel::DoMultiply(int tA, int tB)
{
	int tR = tA * tB;
	UE_LOG(LogTemp, Warning, TEXT("DoMulti: %d"), tR);
	return tA * tB;
}

