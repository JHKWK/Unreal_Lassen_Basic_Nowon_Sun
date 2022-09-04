// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "PwnEnemy.generated.h"

UCLASS()
class UESIMPLESHOOTERCPP_API APwnEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APwnEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnDoFireDefault(); // ¿œπ›≈∫
	void OnDoFireAimed();   // ¡∂¡ÿ≈∫
	void OnDoFireCircled(); // πÊªÁ«¸≈∫
	void OnTimer();

public:

	UPROPERTY(VisibleAnywhere)
		USceneComponent* mpRoot = nullptr;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* mpBody = nullptr;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* mpBoxCollision = nullptr;

	FTimerHandle OnTimerHandle;
	float mTimer = 2;
	int testCount=0;
};
