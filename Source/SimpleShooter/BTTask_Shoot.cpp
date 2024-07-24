// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "ShooterCharacter.h"
#include "AIController.h"

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* OwnerController = OwnerComp.GetAIOwner();

	if (!OwnerController) 
	{
		return EBTNodeResult::Failed;
	}

	AShooterCharacter* AICharacter = Cast<AShooterCharacter>(OwnerController->GetPawn());

	if (!AICharacter)
	{
		return EBTNodeResult::Failed;
	}

	AICharacter->Shoot();

	return EBTNodeResult::Succeeded;
}
