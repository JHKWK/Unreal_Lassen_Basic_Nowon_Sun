// Fill out your copyright notice in the Description page of Project Settings.


#include  "KwkActorDel.h"

// Sets default values
AKwkActorDel::AKwkActorDel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//	Fstring : 일반적인 문자열
//	FText   : 현지화된 텍스트 기능을 지원하는 문자열
//	FName   : 검색용 문자열

// Called when the game starts or when spawned
void AKwkActorDel::BeginPlay()
{
	Super::BeginPlay();
	
	//델리게이트에 함수 연동
	mFuncVoid.BindUFunction(this, FName("Doit"));

	//연동이 유효한지 검사
	if (mFuncVoid.IsBound())
	{
		//델리게이트로 함수 간접호출
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

	//델리게이트 객체 연동관련 데이터 해지

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

