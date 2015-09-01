// Sebastian Kenter

using System;
using System.IO;
using UnrealBuildTool;

public class PhotonTutorial : ModuleRules
{
	public PhotonTutorial(TargetInfo Target)
	{
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }

        LoadPhotonSystem(Target);
	}

    private string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

    private string PhotonPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "..", "Photon")); }
    }

    private void AddPhotonLibPathWin(TargetInfo Target, string name)
    {
        string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "Win32";
        PublicAdditionalLibraries.Add(Path.Combine(PhotonPath, "lib", "Windows", name + "-cpp_vc12_release_windows_md_" + PlatformString + ".lib"));
    }

    public bool LoadPhotonSystem(TargetInfo Target)
    {
        if((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            Definitions.Add("_EG_WINDOWS_PLATFORM");
            AddPhotonLibPathWin(Target, "Common");
            AddPhotonLibPathWin(Target, "Photon");
        }
        else
        {
            throw new Exception("\nTaget platform not supported: " + Target.Platform);
        }

        PublicIncludePaths.Add(Path.Combine(PhotonPath, "."));

        return true;
    }

}
