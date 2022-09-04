// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBullet.h"

// Sets default values
AEnemyBullet::AEnemyBullet()
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
		mpBody->SetRelativeLocation(FVector(0, 0, 50));
		mpBody->SetRelativeScale3D(FVector(0.4f, 0.4f, 0.4f));
	}

	this->Tags.Add("tagBullet");
	this->InitialLifeSpan = 10;


}

// Called when the game starts or when spawned
void AEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector tPosition = FVector::ZeroVector;
	FVector tMoveDir = FVector::ZeroVector;

	tPosition = this->GetActorLocation();
	tMoveDir = this->GetActorForwardVector();

	tPosition = tPosition + tMoveDir * mSpeed * DeltaTime;

	this->SetActorLocation(tPosition);

}

void AEnemyBullet::BeginFirePlay()
{
	//발사 시작할 때 할일
}

