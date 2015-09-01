// Sebastian Kenter

#pragma once

#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(PT, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(PTNet, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(PTLoading, Log, All);

class FPhotonTutorialGameModule : public FDefaultGameModuleImpl
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};