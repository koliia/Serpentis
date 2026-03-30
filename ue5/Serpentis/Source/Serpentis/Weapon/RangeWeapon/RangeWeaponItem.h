// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/Weapon.h"
#include "RangeWeaponItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SERPENTIS_API ARangeWeaponItem : public AWeapon
{
	GENERATED_BODY()
	
public:
	ARangeWeaponItem();
	
	void Fire(FVector Origin, FVector Direction, AController* Controller);
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USkeletalMeshComponent* WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UWeaponBarrelComponent* WeaponBarrel;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animations | Weapon")
	UAnimationAsset* WeaponFireMontage;
};
