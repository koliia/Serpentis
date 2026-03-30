// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/RangeWeapon/RangeWeaponItem.h"

#include "SerpentisTypes.h"
#include "Characters/Base/BaseCharacter.h"
#include "Characters/Controllers/BaseAIController.h"
#include "Weapon/WeaponBarrellComponent.h"

ARangeWeaponItem::ARangeWeaponItem()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponRoot"));
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	WeaponBarrel = CreateDefaultSubobject<UWeaponBarrelComponent>(TEXT("WeaponBarrel"));
	WeaponBarrel->SetupAttachment(WeaponMesh, SocketWeaponMuzzle);
}

void ARangeWeaponItem::Fire(FVector Origin, FVector Direction, AController* Controller)
{
	WeaponMesh->PlayAnimation(WeaponFireMontage, false);
	WeaponBarrel->Shoot(Origin, Direction, Controller);
}
