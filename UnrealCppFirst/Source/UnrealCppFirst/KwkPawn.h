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

	// UPROPERTY ��ũ�δ� ��������� ����
	// Ŭ���� ����Ʈ, �ν��Ͻ� ������ ��𿡼� ������ ����
	// ��������Ʈ���� ���� ���� ����

	// ��������� �ش� UPROPERTY ��ũ�δ�
	// �Ϲ�   (��Ÿ��) ������     EditAnywhere
	// ������ (������) �������Դ� VisibleAnyWhere
	// �� ������ �ִ� ���� �����ϴ�

	UPROPERTY(EditAnywhere)
	int mTest = 777;

	// UPROPERTY(EditAnywhere) -> Ŭ������ ���͹�����
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mpBody = nullptr;

};