// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkPawn.h"
#include "KwkBullet.h"

// Sets default values
AKwkPawn::AKwkPawn()
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
		mpBody->SetRelativeLocation(FVector(0,0,50));
	}

	mpSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("instSpringArm"));
	mpSpringArm->SetupAttachment(mpRoot);
	mpSpringArm->SetRelativeLocation(FVector(0, 0, 50));
	mpSpringArm->SetRelativeRotation(FRotator(-35,0,0));
	mpSpringArm->TargetArmLength = 600;
	mpSpringArm->bEnableCameraLag = true;
	mpSpringArm->bDoCollisionTest = false;

	mpCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("instCamera"));
	mpCamera->SetupAttachment(mpSpringArm);


	//this->Tags.Add("tagPawn");
	this->Tags.Add("tagTarget");

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

	if (!isRotateMode)
	{
		if (!mMovementInput.IsZero())
		{
			FVector tPosition = FVector::ZeroVector;
			FVector tMoveDir = FVector::ZeroVector;

			tPosition = this->GetActorLocation();

			tMoveDir.X = mMovementInput.X;
			tMoveDir.Y = mMovementInput.Y;

			if (tMoveDir.Size() > 1)
			{
				tMoveDir.Normalize();
			}

			tPosition = tPosition + tMoveDir * mSpeed * DeltaTime;

			this->SetActorLocation(tPosition);
		}
	}

	if (isRotateMode)
	{
		if (!mMovementInput.IsZero())
		{
			FVector tPosition = FVector::ZeroVector;
			FVector tMoveDir = FVector::ZeroVector;

			FRotator tRotator = this->GetActorRotation();
			float tRotateSpeed = mMovementInput.Y * 50 * DeltaTime;
			tRotator.Yaw = tRotator.Yaw + tRotateSpeed;

			tPosition = this->GetActorLocation();
			tMoveDir = this->GetActorForwardVector()*mMovementInput.X;

			if (tMoveDir.Size() > 1)
			{
				tMoveDir.Normalize();
			}

			tPosition = tPosition + tMoveDir * mSpeed * DeltaTime;

			this->SetActorLocation(tPosition);
			this->SetActorRotation(tRotator);
		}


	}


}

// Called to bind functionality to input
void AKwkPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("OnMoveForward", this, &AKwkPawn::OnMoveForward);
	PlayerInputComponent->BindAxis("OnMoveRight", this, &AKwkPawn::OnMoveRight);
	PlayerInputComponent->BindAction("OnDoFire", IE_Released, this, &AKwkPawn::OnDoFire);

}

void AKwkPawn::OnMoveForward(float tA)
{
	mMovementInput.X = FMath::Clamp<float>(tA,-1,1);
}

void AKwkPawn::OnMoveRight(float tA)
{
	mMovementInput.Y = FMath::Clamp<float>(tA, -1, 1);
}

void AKwkPawn::OnDoFire()
{
	// UE_LOG(LogClass, Warning, TEXT("OnDoFire"));

	//탄환 발사 루틴
	// 1. 발사 시작 위치지정
	// 2. 탄환의 속도 설정
	// 3. 탄환의 활성화

	FVector tVector = this->GetActorLocation();

	FRotator tDir = this->GetActorRotation();
	AKwkBullet* tpBullet = nullptr;

	UWorld* tpWorld = this->GetWorld();
	tpBullet = tpWorld->SpawnActor<AKwkBullet>(tVector,tDir);


	if (tpBullet)
	{
		UE_LOG(LogClass, Warning, TEXT("Fire!"))
	}

}

