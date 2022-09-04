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

	//�浹ó�� Ȱ��ȭ
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
		//Ÿ�̸� ����(��������Ʈ ����)
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

	//��ȸ���� AActor�迭�� ��ü�� �˻��Ѵ�
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

	���忡 ��ġ�� ���͵��� ���� ����� �ڷᱸ������ �˻��� �Ѵ�
	���� ���� ����� ���͵鸸�� �����ϰ� �ֱ� ������ �÷��̾�� ���ԵǾ� ���� �ʴ�

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
		��ī��Ʈ ��ǥ���� ������ ǥ�������� ��ҿ� ����ǥ�� ǥ�������� ��� ������ ����

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