// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTMenuStyles.h"
#include "SlateGameResources.h"

TSharedPtr<class FSlateStyleSet> PTMenuStyles::PTMenuStyleInstance = NULL;

void PTMenuStyles::Initialize()
{
    if (!PTMenuStyleInstance.IsValid())
    {
        PTMenuStyleInstance = Create();
        FSlateStyleRegistry::RegisterSlateStyle(*PTMenuStyleInstance);
    }
}

void PTMenuStyles::Shutdown()
{
    FSlateStyleRegistry::UnRegisterSlateStyle(*PTMenuStyleInstance);
    ensure(PTMenuStyleInstance.IsUnique());
    PTMenuStyleInstance.Reset();
}

const class ISlateStyle& PTMenuStyles::Get()
{
    return *PTMenuStyleInstance;
}

FName PTMenuStyles::GetStyleSetName()
{
    static FName StyleSetName(TEXT("PTMenuStyles"));
    return StyleSetName;
}

TSharedRef<FSlateStyleSet> PTMenuStyles::Create()
{
    TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(PTMenuStyles::GetStyleSetName(), "/Game/Slate/UI/Styles", "/Game/Slate/UI/Styles");
    return StyleRef;
}