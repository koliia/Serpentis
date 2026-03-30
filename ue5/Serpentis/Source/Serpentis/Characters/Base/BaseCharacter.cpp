// Fill out your copyright notice in the Description page of Project Settings.


#include "Serpentis/Characters/Base/BaseCharacter.h"
#include "Components/CharacterEquipmentComponent.h"
#include "Components/CharacterComponents/CharacterAttributeComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ABaseCharacter::ABaseCharacter()
{
	CharacterEquipmentComponent = CreateDefaultSubobject<UCharacterEquipmentComponent>(TEXT("CharacterEquipment"));
	CharacterAttributeComponent = CreateDefaultSubobject<UCharacterAttributeComponent>(TEXT("CharacterAttributes"));
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	CharacterAttributeComponent->OnDeathEvent.AddDynamic(this, &ABaseCharacter::OnDeath);
}

void ABaseCharacter::OnDeath()
{
	if (IsValid(OnDeathAnimMontage))
	{
		this->PlayAnimMontage(OnDeathAnimMontage);
	}
	else
	{
		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
	}
	//GetCharacterMovement()->DisableMovement();
	if (Controller)
	{
		Controller->UnPossess();
	}
	
	
	//TO-DO clean up code. Turn off shooting when dead. Also turn off animation completely? (make the ragdoll only for AI). If montage is mising -> ragdoll
}

