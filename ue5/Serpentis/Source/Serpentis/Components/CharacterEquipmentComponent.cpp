// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterEquipmentComponent.h"

#include "SerpentisTypes.h"
#include "Characters/Base/BaseCharacter.h"
#include "Weapon/RangeWeapon/RangeWeaponItem.h"


EEquippedItemType UCharacterEquipmentComponent::GetCurrentEquippedItemType() const
{
	EEquippedItemType Result = EEquippedItemType::None;
	// if (IsValid(CurrentEquippedItem))
	// {
	// 	Result = CurrentEquippedItem->GetEquippedItemType();
	// }
	Result = CachedEquippedItemType;
	return Result;
}

void UCharacterEquipmentComponent::SetCurrentEquippedItemType(EEquippedItemType type)
{
	CachedEquippedItemType = type;
}

void UCharacterEquipmentComponent::Fire(FVector Origin, FVector Direction, AController* Controller)
{
	if (IsValid(CurrentEquippedItem) && CachedEquippedItemType != EEquippedItemType::None)
	{
		CurrentEquippedItem->Fire(Origin, Direction, Controller);
	}
}

void UCharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	checkf(GetOwner()->IsA<ABaseCharacter>(), TEXT("ACharacterEquipmentComponent::BeginPlay()"));
	CachedBaseCharacter = StaticCast<ABaseCharacter*>(GetOwner());
	CachedEquippedItemType = EEquippedItemType::None;
	CreateLoadout();
}

void UCharacterEquipmentComponent::CreateLoadout()
{
	if (!IsValid(SideArmClass)) return;
	CurrentEquippedItem = GetWorld()->SpawnActor<ARangeWeaponItem>(SideArmClass);
	CurrentEquippedItem->AttachToComponent(CachedBaseCharacter->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, SocketCharacterWeapon);
	CurrentEquippedItem->SetOwner(CachedBaseCharacter.Get());
}
