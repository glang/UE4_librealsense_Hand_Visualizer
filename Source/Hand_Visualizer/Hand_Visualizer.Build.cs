// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class Hand_Visualizer : ModuleRules
{
    public Hand_Visualizer(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
        PublicAdditionalLibraries.Add("C:/Users/Granger Lang/Documents/Unreal Projects/Hand_Visualizer/ThirdParty/librealsense/Libraries/realsense.lib");
        //PublicAdditionalLibraries.Add("C:/Users/Granger Lang/Documents/Unreal Projects/Hand_Visualizer/ThirdParty/librealsense/Libraries/realsense.dll");
        PublicIncludePaths.Add("C:/Users/Granger Lang/Documents/Unreal Projects/Hand_Visualizer/ThirdParty/librealsense/Includes");
    }
}
