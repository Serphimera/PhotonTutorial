// Sebastian Kenter

#pragma once

#include "SlateBasics.h"

/**
 * 
 */
class PTMenuStyles
{
public:
    static void Initialize();
    static void Shutdown();
    static const class ISlateStyle& Get();
    static FName GetStyleSetName();
private:
    static TSharedRef<class FSlateStyleSet> Create();
    static TSharedPtr<class FSlateStyleSet> PTMenuStyleInstance;
};
