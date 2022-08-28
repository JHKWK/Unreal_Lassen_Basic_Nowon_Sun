// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkPawn.h"

// Sets default values
AKwkPawn::AKwkPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//컴퍼넌트의 조립은 생성자에서 한다
	//매개변수는 이 컴퍼넌트의 오브젝트 식별자이다
	mpBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("instBody"));
	SetRootComponent(mpBody);

	// 컴포넌트에 적합한 오브젝트를 등록하기 위해
	// ConstructorHelpers 클래스가 지원된다
	// FOBjectFInder는 객체를 
	// FClassFInder는 클래스를
	// 찾아서 객체로 돌려준다

	//해당 오브젝트를 찾는데 필요한 문자열은 언리얼 에디터에서 '레퍼런스 카피'메뉴로 얻는다.
	// StaticMesh'/Engine/BasicShapes/Cube.Cube'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> tPFCube(TEXT("/Engine/BasicShapes/Cube.Cube"));

	if (tPFCube.Succeeded())
	{
		mpBody->SetStaticMesh(tPFCube.Object);
	}
}

// Called when the game starts or when spawned
void AKwkPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKwkPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKwkPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

