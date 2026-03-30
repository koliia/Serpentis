// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Serpentis : ModuleRules
{
	public Serpentis(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "Niagara" });

		PublicIncludePaths.AddRange(new string[] {
			"Serpentis",
			"Serpentis/Variant_Platforming",
			"Serpentis/Variant_Platforming/Animation",
			"Serpentis/Variant_Combat",
			"Serpentis/Variant_Combat/AI",
			"Serpentis/Variant_Combat/Animation",
			"Serpentis/Variant_Combat/Gameplay",
			"Serpentis/Variant_Combat/Interfaces",
			"Serpentis/Variant_Combat/UI",
			"Serpentis/Variant_SideScrolling",
			"Serpentis/Variant_SideScrolling/AI",
			"Serpentis/Variant_SideScrolling/Gameplay",
			"Serpentis/Variant_SideScrolling/Interfaces",
			"Serpentis/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
