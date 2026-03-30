// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WeaponBarrellComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SERPENTIS_API UWeaponBarrelComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	void Shoot(FVector ShotStart, FVector ShotDirection, AController* Controller);
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Barell attributes")
	float FiringRange = 5000.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Barell attributes | Damage")
	float DamageAmount = 20.f;
		
	UPROPERTY(EditDefaultsOnly, Category = "VFX")
	class UNiagaraSystem* BulletTraceFX;
};
