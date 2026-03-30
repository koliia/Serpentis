// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/Base/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SERPENTIS_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();
	
	virtual void Look(FVector2D) override;
	virtual void Shoot() override;
	virtual void StartAiming() override;
	virtual void ReleaseAiming() override;
	
	UFUNCTION(BlueprintCallable, Category = "Animation Settings")
	const UCharacterEquipmentComponent* GetCharacterEquipmentComponent() const;
	
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SetCameraLockY(bool condition);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	class UCameraComponent* CameraComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	bool bCameraLocked = false;
};
