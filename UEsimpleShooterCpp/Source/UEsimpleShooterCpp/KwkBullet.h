// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

//�浹�ڽ� ������Ʈ �߰��� ���� ���
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

	//�浹ó�� ��������Ʈ�� ����� �Լ�
	//���¸� ��������Ʈ�� ���߾� �������
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
