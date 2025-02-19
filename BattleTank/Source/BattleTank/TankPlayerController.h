// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//moves the barrel to point to where the crosshair is
	void AimTowardsCrossHair();
	bool GetSiteRayHitLocation(FVector &OutHitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .333333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
};
