// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkBullet.h"

// Sets default values
AKwkBullet::AKwkBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mpRoot = CreateDefaultSubobject<USceneComponent>(TEXT("instSceneRoot"));
	SetRootComponent(mpRoot);

	mpBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("instBody"));
	mpBody->SetupAttachment(mpRoot);

	ConstructorHelpers::FObjectFinder<UStaticMesh> tPFMesh(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (tPFMesh.Succeeded())
	{
		mpBody->SetStaticMesh(tPFMesh.Object);
		mpBody->SetRelativeLocation( FVector(0, 0, 50) );
		mpBody->SetRelativeScale3D( FVector(0.4f, 0.4f, 0.4f) );
	}

	//�浹�ڽ� ���۳�Ʈ�� ����� ����
	mpBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("instCollision"));
	mpBoxCollision->SetupAttachment(mpRoot);

	//�浹ó�� Ȱ��ȭ
	SetActorEnableCollision(true);
	//�浹ó�� �Լ� ���
	OnActorBeginOverlap.AddDynamic(this, &AKwkBullet::OnOverlapBegin);

	this->Tags.Add("tagBullet");
	//this->SetLifeSpan(5.0f);
	this->InitialLifeSpan=5;

}

// Called when the game starts or when spawned
void AKwkBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKwkBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector tPosition = FVector::ZeroVector;
	FVector tMoveDir = FVector::ZeroVector;

	tPosition = this->GetActorLocation();
	tMoveDir = this->GetActorForwardVector();

	tPosition = tPosition + tMoveDir * mSpeed * DeltaTime;

	this->SetActorLocation(tPosition);

}

void AKwkBullet::BeginFirePlay()
{
	//�߻� ������ �� ����
}

void AKwkBullet::OnOverlapBegin( class AActor* OverlappedActor, class AActor* OtherActor )
{
	if (OtherActor->ActorHasTag("tagEnemy"))
	{
		UE_LOG(LogClass, Log, TEXT(" %s"), *OtherActor->GetName());

		this->Destroy();
		OtherActor->Destroy();
	}
}
