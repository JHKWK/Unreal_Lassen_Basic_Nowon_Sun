// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkEnemy.h"

// Sets default values
AKwkEnemy::AKwkEnemy()
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

	//충돌처리 함수 등록
	OnActorBeginOverlap.AddDynamic(this, &AKwkEnemy::OnOverlapBegin);
	this->Tags.Add("tagEnemy");
}

// Called when the game starts or when spawned
void AKwkEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKwkEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKwkEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AKwkEnemy::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("tagBullet"))
	{
		UE_LOG(LogClass, Log, TEXT(" %s"), *OtherActor->GetName());
	}
}

