// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UNREALCPPFIRST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//�𸮾� ��ũ��, ��������� �Ӽ��� ���� �Ͽ���
	UPROPERTY(EditAnywhere, Category="KWK")
	float mTestKwk = 0.0f;
	UPROPERTY(EditAnywhere, Category = "KWK")
	float mTestKwk2 = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "KWK")
		void Doit();

};
