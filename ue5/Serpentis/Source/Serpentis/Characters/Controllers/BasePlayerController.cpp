// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Controllers/BasePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/Base/BaseCharacter.h"
#include "Characters/PlayerCharacter/PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"

void ABasePlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedBaseCharacter = Cast<ABaseCharacter>(InPawn);
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (PlayerInputContext)
			{
				Subsystem->AddMappingContext(PlayerInputContext, 0);
			}
		}
	}
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (LookAction)
			EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABasePlayerController::Look);
		if (ShootAction)
			EIC->BindAction(ShootAction, ETriggerEvent::Triggered, this, &ABasePlayerController::Shoot);
		if (AimStartAction)
			EIC->BindAction(AimStartAction, ETriggerEvent::Triggered, this, &ABasePlayerController::StartAiming);
		if (AimReleaseAction)
			EIC->BindAction(AimReleaseAction, ETriggerEvent::Triggered, this, &ABasePlayerController::ReleaseAiming);
	}
}


void ABasePlayerController::Look(const FInputActionValue& Value)
{
	if (!CachedBaseCharacter.IsValid()) return;
	CachedBaseCharacter->Look(Value.Get<FVector2D>());
}

void ABasePlayerController::Shoot()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Shoot();
	}
}

void ABasePlayerController::StartAiming()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->StartAiming();
	}
}

void ABasePlayerController::ReleaseAiming()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->ReleaseAiming();
	}
}

