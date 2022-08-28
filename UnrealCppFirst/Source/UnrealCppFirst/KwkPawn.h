// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KwkPawn.generated.h"

UCLASS()
class UNREALCPPFIRST_API AKwkPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKwkPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	// UPROPERTY 매크로는 멤버변수에 적용
	// 클래스 디폴트, 인스턴스 디테일 어디에서 보일지 여부
	// 블루프린트에서 관찰 가능 여부

	// 멤버변수의 해당 UPROPERTY 매크로는
	// 일반   (값타입) 변수는     EditAnywhere
	// 포인터 (참조형) 변수에게는 VisibleAnyWhere
	// 를 적용해 주는 것이 편리하다

	UPROPERTY(EditAnywhere)
	int mTest = 777;

	// UPROPERTY(EditAnywhere) -> 클래스가 나와버린다
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mpBody = nullptr;

};
