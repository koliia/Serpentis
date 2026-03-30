// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerpentisTypes.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class SERPENTIS_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	EEquippedItemType GetEquippedItemType() const;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipable item")
	EEquippedItemType ItemType = EEquippedItemType::None;

};
