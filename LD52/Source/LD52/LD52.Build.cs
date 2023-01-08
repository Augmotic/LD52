// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LD52 : ModuleRules
{
	public LD52(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
