// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller Begin Play is being called"));
	GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	//Get World location by line trace to crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point
}

ATank* ATankPlayerController::GetControlledTank() const {
	ATank *PlayerTank= Cast<ATank>(GetPawn());

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("The player is controlling %s"),*(PlayerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The player tank has not been found"));
	}

	return PlayerTank;
}


