#pragma once
#define ECC_Bullet ECC_GameTraceChannel1

const FName SocketCharacterWeapon = FName("WeaponSocket");
const FName SocketWeaponMuzzle = FName("MuzzleSocket");

const FName FXParamTraceEnd = FName("TraceEnd");

UENUM(BlueprintType)
enum class EEquippedItemType : uint8
{
	None,
	Pistol
};