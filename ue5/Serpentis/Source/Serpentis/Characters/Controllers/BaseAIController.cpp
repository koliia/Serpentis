// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Controllers/BaseAIController.h"

#include "Characters/Base/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
	TargetPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void ABaseAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<ABaseCharacter>(InPawn);
}

void ABaseAIController::ShootAtPlayer()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Shoot();
	}
}
