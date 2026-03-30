// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter/PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

APlayerCharacter::APlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArm);
}

void APlayerCharacter::Look(FVector2D Value)
{
	Super::Look(Value);
	AddControllerYawInput(Value.X * 0.5);
	if (!bCameraLocked)
		AddControllerPitchInput(Value.Y * 0.5);
}

void APlayerCharacter::Shoot()
{
	Super::Shoot();
	FVector ViewPoint;
	FRotator ViewRotation;
	Controller->GetPlayerViewPoint(ViewPoint, ViewRotation);
	CharacterEquipmentComponent->Fire(ViewPoint, ViewRotation.Vector(), Controller);
}

void APlayerCharacter::StartAiming()
{
	Super::StartAiming();
	if (IsValid(CharacterEquipmentComponent)) CharacterEquipmentComponent->SetCurrentEquippedItemType(EEquippedItemType::Pistol);
}

void APlayerCharacter::ReleaseAiming()
{
	Super::ReleaseAiming();
	if (IsValid(CharacterEquipmentComponent)) CharacterEquipmentComponent->SetCurrentEquippedItemType(EEquippedItemType::None);
}

const UCharacterEquipmentComponent* APlayerCharacter::GetCharacterEquipmentComponent() const
{
	return CharacterEquipmentComponent;
}

void APlayerCharacter::SetCameraLockY(bool condition)
{
	bCameraLocked = condition;
}
