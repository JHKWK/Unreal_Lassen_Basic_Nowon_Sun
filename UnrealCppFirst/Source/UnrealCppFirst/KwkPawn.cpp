// Fill out your copyright notice in the Description page of Project Settings.


#include "KwkPawn.h"

// Sets default values
AKwkPawn::AKwkPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

// Called to bind functionality to input
void AKwkPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

