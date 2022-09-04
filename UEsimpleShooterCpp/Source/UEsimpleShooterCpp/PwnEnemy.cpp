// Fill out your copyright notice in the Description page of Project Settings.


#include "PwnEnemy.h"
#include "EnemyBullet.h"
#include "RunTime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
APwnEnemy::APwnEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mpRoot = CreateDefaultSubobject<USceneComponent>(TEXT("instSceneRoot"));
	SetRootComponent(mpRoot);

	mpBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("instBody"));
	mpBody->SetupAttachment(mpRoot);

	ConstructorHelpers::FObjectFinder<UStaticMesh> tPFMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));

	if (tPFMesh.Succeeded())
	{
		mpBody->SetStaticMesh(tPFMesh.Object);
		mpBody->SetRelativeLocation(FVector(0, 0, 50));
	}

	mpBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("instCollision"));
	mpBoxCollision->SetupAttachment(mpRoot);

	//충돌처리 활성화
	SetActorEnableCollision(true);
	this->Tags.Add("tagEnemy");
}

// Called when the game starts or when spawned
void APwnEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(OnTimerHandle, this, &APwnEnemy::OnTimer, mTimer,true);
	
}

// Called every frame
void APwnEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APwnEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APwnEnemy::OnTimer()
{
	UE_LOG(LogClass, Log, TEXT("APwnEnemy::OnTimer()"));

	if (testCount < 5)
	{
		//OnDoFireDefault();
		//OnDoFireAimed();
		OnDoFireCircled();
		//testCount++;
	}
	else
	{
		//타이머 해제(델리게이트 해제)
		UE_LOG(LogClass, Log, TEXT("StopTimer"));

		GetWorld()->GetTimerManager().ClearTimer(OnTimerHandle);
	}
	
}

void APwnEnemy::OnDoFireDefault()
{

	FVector tVector = this->GetActorLocation();

	FRotator tDir = this->GetActorRotation();
	AEnemyBullet* tpBullet = nullptr;

	UWorld* tpWorld = this->GetWorld();
	tpBullet = tpWorld->SpawnActor<AEnemyBullet>(tVector, tDir);

	if (tpBullet)
	{
		UE_LOG(LogClass, Warning, TEXT("Fire!"))
	}

}

void APwnEnemy::OnDoFireAimed()
{
	FVector tVector = this->GetActorLocation();
	FRotator tDir = FRotator::ZeroRotator;
	AActor* tpActor= nullptr;

	/*
	case 0 

	//순회구문 AActor계열의 객체를 검색한다
	for (TObjectIterator<AActor>tItor; tItor; ++tItor)
	{
		if ((*tItor)->ActorHasTag("tagTarget"))
		{
			UE_LOG(LogClass, Warning, TEXT("Target Found"));
				tpActor = *tItor;
		}
	}
	if (nullptr == tpActor)
	{
		return;
	}

	월드에 배치된 액터들을 상대로 구축된 자료구조에서 검색을 한다
	실행 전에 구축된 액터들만을 포함하고 있기 때문에 플레이어는 포함되어 있지 않다

	*/

	TArray<AActor*> tPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), tPawns);
	for (int i = 0; i < tPawns.Num(); i++)
	{
		if (tPawns[i]->ActorHasTag("tagTarget"))
		{
			UE_LOG(LogClass, Warning, TEXT("Target Found"));
			tpActor = tPawns[i];

			break;
		}		
	}


	FVector tVectorTarget = tpActor->GetActorLocation();
	FVector tVectorStart = tVector;

	FVector tVectorTmp =  tVectorTarget-tVectorStart;


	tVectorTmp = tVectorTmp.GetSafeNormal();
	tDir = tVectorTmp.Rotation();

	AEnemyBullet* tpBullet = nullptr;

	UWorld* tpWorld = this->GetWorld();
	tpBullet = tpWorld->SpawnActor<AEnemyBullet>(tVector, tDir);

	if (tpBullet)
	{
		UE_LOG(LogClass, Warning, TEXT("Fire!"))
	}

}

void APwnEnemy::OnDoFireCircled()
{

	FVector tVector = this->GetActorLocation();

	FRotator tDir = this->GetActorRotation();
	AEnemyBullet* tpBullet = nullptr;
	UWorld* tpWorld = this->GetWorld();

	/*
		데카르트 좌표계의 수벡터 표기형식의 요소와 극좌표계 표기형식의 요소 사이의 관계

		x = r * cosT
		y = r * sinT

	*/

	for (int i = 0; i < 36; i++)
	{
		FVector tVectorDir = FVector::ZeroVector;

		tVectorDir.X = 1 * FMath::Cos(FMath::DegreesToRadians(10*i));
		tVectorDir.Y = 1 * FMath::Sin(FMath::DegreesToRadians(10*i));
		tDir = tVectorDir.Rotation();

		tpBullet = tpWorld->SpawnActor<AEnemyBullet>(tVector, tDir);
	}
	/*
	for (int i=0; i < 36; i++)
	{
		tDir = tDir + FRotator(0,10*i,0);
		tpBullet = tpWorld->SpawnActor<AEnemyBullet>(tVector, tDir);
	}
	*/

	if (tpBullet)
	{
		UE_LOG(LogClass, Warning, TEXT("Fire!"))
	}

}