// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTPhotonListener.h"

PTPhotonListener::PTPhotonListener()
{
}

void PTPhotonListener::onOperationResponse(const OperationResponse& operationResponse)
{
    if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
    {
        CurrentHandler->HandleOnOperationResponse(operationResponse);
    }
}

void PTPhotonListener::onStatusChanged(int statusCode)
{
    if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
    {
        CurrentHandler->HandleOnStatusChanged(statusCode);
    }
}

void PTPhotonListener::onEvent(const EventData& eventData)
{
    if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
    {
        CurrentHandler->HandleOnEvent(eventData);
    }
}

void PTPhotonListener::debugReturn(int debugLevel, const JString& string)
{
    if (CurrentHandler && CurrentHandler->IsValidLowLevelFast(true))
    {
        CurrentHandler->HandleDebugReturn(debugLevel, string);
    }
}

void PTPhotonListener::setCurrentHandler(UPTPhotonBaseHandler* Handler)
{
    if (Handler && Handler->IsValidLowLevelFast(true))
    {
        CurrentHandler = Handler;
    }
}