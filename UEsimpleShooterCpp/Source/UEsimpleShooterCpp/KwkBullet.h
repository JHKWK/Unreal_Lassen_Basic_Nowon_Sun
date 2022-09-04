// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

//충돌박스 컴포넌트 추가를 위한 헤더
#include "Components/BoxComponent.h"

#include "KwkBullet.generated.h"

UCLASS()
class UESIMPLESHOOTERCPP_API AKwkBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKwkBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BeginFirePlay();

	//충돌처리 델리게이트에 등록할 함수
	//형태를 델리게이트에 맞추어 만들었다
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor,class AActor* OtherActor);

public:

	UPROPERTY(VisibleAnywhere)
		USceneComponent* mpRoot = nullptr;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* mpBody = nullptr;

	UPROPERTY(EditAnyWhere, Category = "KWK")
		float mSpeed = 2500;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* mpBoxCollision = nullptr;


};
