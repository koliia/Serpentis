// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponBarrellComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "SerpentisTypes.h"
#include "Engine/DamageEvents.h"

void UWeaponBarrelComponent::Shoot(FVector ShotStart, FVector ShotDirection, AController* Controller)
{
	FVector MuzzleLocation = GetComponentLocation();
	FVector ShotEnd = ShotStart + FiringRange * ShotDirection;
	
	FHitResult ShotHitResult;
	if (GetWorld()->LineTraceSingleByChannel(ShotHitResult, ShotStart, ShotEnd, ECC_Bullet))
	{
		//UE_LOG(LogTemp, Error, TEXT("%f, %f, %f"), ShotEnd.X, ShotEnd.Y, ShotEnd.Z)
		ShotEnd = ShotHitResult.ImpactPoint;
		//DrawDebugSphere(GetWorld(), ShotEnd, 10.0f, 24, FColor::Red, false, 1.0f);
		AActor* HitActor = ShotHitResult.GetActor();
		if (IsValid(HitActor))
		{
			HitActor->TakeDamage(DamageAmount, FDamageEvent{}, Controller, GetOwner());
		}
	}
	//DrawDebugLine(GetWorld(), MuzzleLocation, ShotEnd, FColor::Red, false, 1.0f, 0, 3.0f);
	if (BulletTraceFX)
	{
		if (UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), BulletTraceFX, MuzzleLocation, GetComponentRotation()))
		{
			NiagaraComp->SetVectorParameter(FXParamTraceEnd, ShotEnd);
		}
	}
}
