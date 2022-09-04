// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UECppFPSProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class AUECppFPSProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	AUECppFPSProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


private:
	UPROPERTY()
		int testPrivate = 9; // 이 변수는 어디에도 표시되지 않는다.

	UPROPERTY(meta = (AllowPrivateAccess = "true")) // 이 변수는 어디에도 표시되지 않는다.
		int testPrivateAcess = 99;

	UPROPERTY(VisibleDefaultsOnly) // '블루프린트 클래스 에디터'에 '클래스 디폴트 디테일 편집창'에 보인다.
		int testDefaultsPrivate = 999;

	UPROPERTY(VisibleInstanceOnly) //  인스턴스의 디테일 편집창에만 보인다.
		int testInstancePrivate = 9999;
	/*
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly) // 블루프린트에서 접근 할 때는 자식오브젝트에서 접근하므로 private로 지정시 컴파일이 되지 않는다.
		int testDefaultsPrivateBPReadOnly = 7;	*/

	//블루프린트 사용옵션이 설정되 있지 않으므로 AllowPrivateAcess가 무용지물이 되었다
	//클래스 디폴트에는 보이지만 블루프린트에디터에는 보이지 않는다
	UPROPERTY(VisibleDefaultsOnly, meta = (AllowPrivateAccess = "true"))
		int testDefaultsPrivateAccess = 7;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		int testDefaultsPrivateAccessBPReadOnly = 7;

protected :
	UPROPERTY()
		int testProtected = 3;

	UPROPERTY(meta = (AllowPrivateAccess = "true")) // 이 변수는 어디에도 표시되지 않는다.
		int testProtectedAcess = 33;
	
};

