// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SecondShooter : ModuleRules
{
	public SecondShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks", "GameplayTags", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities" , "GameplayAbilitiesEditor" , "GameplayTags" , "GameplayTagsEditor", "GameplayTasks", "Slate" , "SlateCore" , "UMG" });
	}
}
