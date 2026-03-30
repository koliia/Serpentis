// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/BaseCharacter.h"
#include "GameFramework/Pawn.h"
#include "EnemyCharacter.generated.h"

UCLASS(Blueprintable)
class SERPENTIS_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	virtual void Shoot() override;
	
	AEnemyCharacter();
	
	virtual void BeginPlay() override;

private:
	
	TWeakObjectPtr<APawn> CachedPlayerPawn;
};
