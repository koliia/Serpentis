// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemy/EnemyCharacter.h"

#include "Characters/Controllers/BaseAIController.h"
#include "Kismet/GameplayStatics.h"


void AEnemyCharacter::Shoot()
{
	Super::Shoot();
	FVector Muzzle = GetMesh()->GetSocketLocation(SocketWeaponMuzzle);
	Muzzle.Z += 10.0f;
	FVector Direction = (CachedPlayerPawn->GetActorLocation() - Muzzle).GetSafeNormal();
	CharacterEquipmentComponent->Fire(Muzzle, Direction, Controller);
}

AEnemyCharacter::AEnemyCharacter()
{
	AIControllerClass = ABaseAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	CachedPlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	CharacterEquipmentComponent->SetCurrentEquippedItemType(EEquippedItemType::Pistol);
}
