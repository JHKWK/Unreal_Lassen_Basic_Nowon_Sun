// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkActor.h"
#include "MyGameInstance.h"

// Sets default values
AKwkActor::AKwkActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//유니코드를 다루기 위하여 L이나 TEXT매크로를 사용한다
	//로그 카테고리, 로그 상세수준
	UE_LOG(LogTemp, Log, L"Kwk_log - AKwkActor::AKwkActor()");
	UE_LOG(LogTemp, Log, TEXT("Kwk_log - AKwkActor::AKwkActor()"));
}

// Called when the game starts or when spawned
void AKwkActor::BeginPlay()
{
	Super::BeginPlay();

	//==============================================================================================

	UE_LOG(LogTemp, Log, L"Kwk_log - AKwkActor::BeginPlay()");
	UE_LOG(LogClass, Log, TEXT("BeginPlay()"));

	UE_LOG(LogClass, Warning, TEXT("BeginPlay()"));

	// TEXT()를 이용하여 유니코드로 다뤄준다
	FString tString_1 = TEXT("꽉kkkk");

	//UE_LOG에서 FString타입 문자열 사용시 간접참조를 해야한다
	UE_LOG(LogClass, Log, TEXT("%s"), *tString_1);


	//서식을 지정하여 문자열을 완성
	// %s : 문자열에 대응
	// %d : 정수형
	// %f : 실수형

	bool tisKwk = false;
	UE_LOG(LogClass, Log, L"Kwk_Log Bool %s", tisKwk ? TEXT("true") : TEXT("flase"));

	int tHP = 1024;
	UE_LOG(LogClass, Log, L"Kwk_Log Int %d", tHP);

	float tExp = 777.9f;
	UE_LOG(LogClass, Log, L"Kwk_Log Float %f", tExp);

	FVector tVector;
	tVector.X = 10;
	tVector.Y = 50;
	tVector.Z = 60;
	UE_LOG(LogClass, Log, L"Kwk_Log Vector3 %s", *tVector.ToString());

	//=============================================================================================

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("KWK 애드온 스크린"));
	
	FString tString_2 = TEXT("테스트 애드온 스크린");
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, tString_2);

	int tLevel = 777;
	FString tString_3 = FString::Printf(TEXT("KWK Log %d, %s"),tLevel,*tString_2);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, tString_3);

	// 키가 중복되는경우 가장 마지막에 실행된 코드로 덮혀진다
	// 첫번째 매개변수 '-1'은 유니크 키 이다, 겹치지 않는 키가 자동 생성된다
	GEngine->AddOnScreenDebugMessage(10, 25.0f, FColor::Black, TEXT("Kwk_00"));
	GEngine->AddOnScreenDebugMessage(10, 25.0f, FColor::Black, TEXT("Kwk_11"));


	//=============================================================================================
	UE_LOG(LogClass, Warning, TEXT("mGameInst: %d"), GetGameInstance<UMyGameInstance>()->mTestKwk);

}

// Called every frame
void AKwkActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

