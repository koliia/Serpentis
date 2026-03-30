// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CharacterEquipmentComponent.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract, NotBlueprintable)
class SERPENTIS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	
	virtual void BeginPlay() override;
	
	virtual void Look(FVector2D Value) {};
	virtual void Shoot() {};
	virtual void StartAiming() {};
	virtual void ReleaseAiming() {};

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	UCharacterEquipmentComponent* CharacterEquipmentComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Components")
	class UCharacterAttributeComponent* CharacterAttributeComponent;
	
	UFUNCTION()
	virtual void OnDeath();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character | Animations")
	class UAnimMontage* OnDeathAnimMontage;
};
