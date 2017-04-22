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

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//moves the barrel to point to where the crosshair is
	void AimTowardsCrossHair();
	
	
};
