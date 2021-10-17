// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class App : ModuleRules
{
	public App(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//bUseRTTI = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Slate", "SlateCore"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		PublicIncludePaths.Add("O:/etreia/ue/App/Source/ThirdParty/");
		PublicIncludePaths.Add("O:/etreia/ue/App/Source/App/Game/Include/");
		PublicIncludePaths.Add("O:/etreia/ue/App/Source/App/GameData/Include/");
		PublicIncludePaths.Add("O:/etreia/ue/App/Source/App/Gui/Include/");
		PublicIncludePaths.Add("O:/etreia/ue/App/Source/App/Keystorm/Include/");
		PublicIncludePaths.Add("O:/etreia/ue/App/Source/App/Module/Include/");

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
