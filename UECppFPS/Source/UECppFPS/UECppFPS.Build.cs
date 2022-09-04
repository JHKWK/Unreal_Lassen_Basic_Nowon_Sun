// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UECppFPS : ModuleRules
{
	public UECppFPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
