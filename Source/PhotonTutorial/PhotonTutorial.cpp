// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTMenuStyles.h"

DEFINE_LOG_CATEGORY(PT);
DEFINE_LOG_CATEGORY(PTNet);
DEFINE_LOG_CATEGORY(PTLoading);

void FPhotonTutorialGameModule::StartupModule()
{
    FSlateStyleRegistry::UnRegisterSlateStyle(PTMenuStyles::GetStyleSetName());
    PTMenuStyles::Initialize();
}

void FPhotonTutorialGameModule::ShutdownModule()
{
    PTMenuStyles::Shutdown();
}

IMPLEMENT_PRIMARY_GAME_MODULE(FPhotonTutorialGameModule, PhotonTutorial, "PhotonTutorial");
