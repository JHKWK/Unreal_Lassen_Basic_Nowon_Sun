// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"


#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "KwkPawn.generated.h"

UCLASS()
class UESIMPLESHOOTERCPP_API AKwkPawn : public APawn
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
	void OnMoveForward(float tAxisValue);
	void OnMoveRight(float tAxisValue);
	void OnDoFire();


public:


	UPROPERTY(VisibleAnywhere)
		USceneComponent* mpRoot = nullptr;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* mpBody = nullptr;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* mpSpringArm = nullptr;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* mpCamera = nullptr;

	UPROPERTY(VisibleAnyWhere, Category = "KWK")
		FVector2D mMovementInput;

	UPROPERTY(EditAnyWhere, Category = "KWK")
		float mSpeed = 500;

	UPROPERTY(EditAnyWhere, Category = "KWK")
		bool isRotateMode = true;

	UPROPERTY(EditAnyWhere, Category = "KWK")
		float mRotateAngle = 50;


};
