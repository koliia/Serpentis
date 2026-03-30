// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterComponents/CharacterAttributeComponent.h"

#include "Characters/Base/BaseCharacter.h"
#include "Components/CapsuleComponent.h"

UCharacterAttributeComponent::UCharacterAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCharacterAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
	checkf(GetOwner()->IsA<ABaseCharacter>(), TEXT("UCharacterAttributeComponent::BeginPlay() Attributes component can work only with ABaseCharacter class"));
	CachedBaseCharacterOwner = StaticCast<ABaseCharacter*>(GetOwner());
	Health = MaxHealth;
	CachedBaseCharacterOwner->OnTakeAnyDamage.AddDynamic(this, &UCharacterAttributeComponent::OnTakeAnyDamage);
}

void UCharacterAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	DebugDrawAttributes();
#endif

}

void UCharacterAttributeComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage,
	const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (!IsAlive()) return;
	
	UE_LOG(LogDamage, Warning, TEXT("UCharacterAttributeComponent::OnTakeAnyDamage %s received %.2f damage from %s"), *DamagedActor->GetName(), Damage, *DamageCauser->GetName());
	Health = FMath::Clamp(Health-Damage, 0.0f, MaxHealth);
	
	if (Health <= 0.0f)
	{
		UE_LOG(LogDamage, Warning, TEXT("UCharacterAttributeComponent::OnTakeAnyDamage character %s is killed by an actor %s"), *DamagedActor->GetName(), *DamageCauser->GetName());
		if (OnDeathEvent.IsBound())
		{
			OnDeathEvent.Broadcast();
		}
	} 
}

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
void UCharacterAttributeComponent::DebugDrawAttributes()
{
	FVector TextLocation = CachedBaseCharacterOwner->GetActorLocation() + (CachedBaseCharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() + 5.0f) * FVector::UpVector;
	DrawDebugString(GetWorld(), TextLocation, FString::Printf(TEXT("Health: %.2f"), Health), nullptr, FColor::Green, 0.0f, true);
}
#endif
