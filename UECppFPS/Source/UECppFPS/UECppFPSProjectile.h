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
		int testPrivate = 9; // �� ������ ��𿡵� ǥ�õ��� �ʴ´�.

	UPROPERTY(meta = (AllowPrivateAccess = "true")) // �� ������ ��𿡵� ǥ�õ��� �ʴ´�.
		int testPrivateAcess = 99;

	UPROPERTY(VisibleDefaultsOnly) // '�������Ʈ Ŭ���� ������'�� 'Ŭ���� ����Ʈ ������ ����â'�� ���δ�.
		int testDefaultsPrivate = 999;

	UPROPERTY(VisibleInstanceOnly) //  �ν��Ͻ��� ������ ����â���� ���δ�.
		int testInstancePrivate = 9999;
	/*
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly) // �������Ʈ���� ���� �� ���� �ڽĿ�����Ʈ���� �����ϹǷ� private�� ������ �������� ���� �ʴ´�.
		int testDefaultsPrivateBPReadOnly = 7;	*/

	//�������Ʈ ���ɼ��� ������ ���� �����Ƿ� AllowPrivateAcess�� ���������� �Ǿ���
	//Ŭ���� ����Ʈ���� �������� �������Ʈ�����Ϳ��� ������ �ʴ´�
	UPROPERTY(VisibleDefaultsOnly, meta = (AllowPrivateAccess = "true"))
		int testDefaultsPrivateAccess = 7;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		int testDefaultsPrivateAccessBPReadOnly = 7;

protected :
	UPROPERTY()
		int testProtected = 3;

	UPROPERTY(meta = (AllowPrivateAccess = "true")) // �� ������ ��𿡵� ǥ�õ��� �ʴ´�.
		int testProtectedAcess = 33;
	
};

