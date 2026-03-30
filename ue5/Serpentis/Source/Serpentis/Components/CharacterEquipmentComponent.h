// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SerpentisTypes.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "CharacterEquipmentComponent.generated.h"

class ARangeWeaponItem;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SERPENTIS_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Animation Settings")
	EEquippedItemType GetCurrentEquippedItemType() const;
	
	//serves the purpose when there is only one weapon in the game
	void SetCurrentEquippedItemType(EEquippedItemType type);
	
	void Fire(FVector Origin, FVector Direction, AController* Controller);
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loadout")
	TSubclassOf<ARangeWeaponItem> SideArmClass;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Loadout")
	ARangeWeaponItem* CurrentEquippedItem;
	
	//serves the purpose when there is only one weapon in the game
	EEquippedItemType CachedEquippedItemType;
	
	void CreateLoadout();
	TWeakObjectPtr<class ABaseCharacter> CachedBaseCharacter;
};
