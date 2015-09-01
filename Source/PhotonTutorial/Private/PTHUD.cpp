// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTHUD.h"

APTHUD::APTHUD(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{

}

void APTHUD::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    SAssignNew(MainMenuUI, SPTMainMenuUI).MainMenuHUD(this);
    
    if (GEngine->IsValidLowLevel())
    {
        GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef()));
    }

}