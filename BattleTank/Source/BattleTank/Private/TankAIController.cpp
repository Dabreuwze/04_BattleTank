// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay(){
	Super::BeginPlay();
	ATank* AITank= GetAIControlledTank();
	ATank* PlayerTank = GetPlayerTank();


	if (AITank) {
		UE_LOG(LogTemp, Warning, TEXT("The AI is controlling %s"), *(AITank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The AI tank has not been found"));
	}

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("The AI found player: %s"), *(PlayerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The player tank has not been found"));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AimTowardsCrossHair();

}

ATank * ATankAIController::GetAIControlledTank(){
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank()
{
	ATank* Player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return Player;
}

void ATankAIController::AimTowardsCrosshair()
{
}

bool ATankAIController::GetSiteRayHitLocation(FVector) const
{
	return false;
}





