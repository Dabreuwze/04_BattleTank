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

	FVector HitLocation;//out parameter

	if (GetSiteRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		//TODO tell controlled tank to aim at this point
	}
}

//Get World location by line trace to crosshair
//if it hits the landscape return true
ATank* ATankPlayerController::GetControlledTank() const {
	ATank *PlayerTank= Cast<ATank>(GetPawn());

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("The player tank has not been found"));
	}

	return PlayerTank;
}

bool ATankPlayerController::GetSiteRayHitLocation(FVector &OutHitLocation) const
{

//	OutHitLocation = GetWorld()->GetFirstPlayerController->GetPlayerViewPoint();
	//Find Cross-hair position
	int32 viewportSizeX;
	int32 viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	
	FVector2D CrossHairPosition=FVector2D(viewportSizeX*CrossHairXLocation, viewportSizeY*CrossHairYLocation);

	//"De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(CrossHairPosition, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Screen Projection: %s"), *LookDirection.ToString());
	}
	//Line trace along that direction and see what is hit (up to maximum range)
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector WorldLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
	
	return true;
}
