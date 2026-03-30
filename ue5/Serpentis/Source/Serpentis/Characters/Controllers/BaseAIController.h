// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class SERPENTIS_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void SetPawn(APawn* InPawn) override;
	
	UFUNCTION(BlueprintCallable)
	void ShootAtPlayer();

private:
	APawn* TargetPawn;
	
	TSoftObjectPtr<class ABaseCharacter> CachedBaseCharacter;
};
