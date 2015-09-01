// Sebastian Kenter

#pragma once

#include "GameFramework/HUD.h"
#include "SPTMainMenuUI.h"
#include "PTHUD.generated.h"

/**
 * 
 */
UCLASS()
class PHOTONTUTORIAL_API APTHUD : public AHUD
{
    GENERATED_UCLASS_BODY()

    virtual void PostInitializeComponents() override;

    UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
        void LogInClicked();

    UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
        void CancelClicked();
	
    TSharedPtr<class SPTMainMenuUI> MainMenuUI;
};
