// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathEventSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SERPENTIS_API UCharacterAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCharacterAttributeComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable)
	FOnDeathEventSignature OnDeathEvent;

	UFUNCTION(BlueprintCallable, Category = "Character | Attributes")
	bool IsAlive() const { return Health > 0.0f; };
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (UIMin = 0.0f))
	float MaxHealth = 10.0f;
	
private:
	float Health = 0.0f;
	
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	void DebugDrawAttributes();
#endif
	
	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	TWeakObjectPtr<class ABaseCharacter> CachedBaseCharacterOwner;
		
};
