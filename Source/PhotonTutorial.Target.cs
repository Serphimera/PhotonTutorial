// Sebastian Kenter

using UnrealBuildTool;
using System.Collections.Generic;

public class PhotonTutorialTarget : TargetRules
{
	public PhotonTutorialTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "PhotonTutorial" } );
	}
}
