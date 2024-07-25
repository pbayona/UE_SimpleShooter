// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* Pawn)
{
	Super::PawnKilled(Pawn);

	APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController());
	
	// Player dead = Game Lost
	if (PlayerController != nullptr) 
	{
		EndGame(false);
		return;
	}

	// Loop over ShooterAI to check all dead
	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld())) 
	{
		if (!Controller->IsDead()) {
			return;
		}
	}
	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bHasWin = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bHasWin);
	}
}
