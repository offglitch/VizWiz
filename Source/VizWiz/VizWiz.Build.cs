// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VizWiz : ModuleRules
{
	public VizWiz(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "TimeSynth", "AudioMixer", "HeadMountedDisplay" });
		
		//for a simpler path of #include
		PublicIncludePaths.AddRange(new string[]
        {
			"VizWiz/Controller",
			"VizWiz/SpectralPlayer",
			"VizWiz/SpectralVisualizers",
			"VizWiz/UI"
        });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
