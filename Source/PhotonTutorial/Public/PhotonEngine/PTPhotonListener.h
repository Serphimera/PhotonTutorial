// Sebastian Kenter

#pragma once

#include "PhotonImport.h"
#include "PTPhotonBaseHandler.h"

using namespace ExitGames::Common;
using namespace ExitGames::Photon;

/**
 * 
 */
class PTPhotonListener : public PhotonListener
{
public:
	PTPhotonListener();

    virtual void onOperationResponse(const OperationResponse& operationResponse) override;

    virtual void onStatusChanged(int statusCode) override;

    virtual void onEvent(const EventData& eventData) override;

    virtual void debugReturn(int debugLevel, const JString& string) override;

    void setCurrentHandler(UPTPhotonBaseHandler* Handler);

private:
    UPROPERTY()
        UPTPhotonBaseHandler* CurrentHandler;
};
