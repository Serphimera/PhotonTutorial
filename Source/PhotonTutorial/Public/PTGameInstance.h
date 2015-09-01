// Sebastian Kenter

#pragma once

#include "Engine/GameInstance.h"
#include "PTPhotonClient.h"
#include "PTPhotonBaseHandler.h"
#include "PTGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PHOTONTUTORIAL_API UPTGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

    virtual void Init() override;

    virtual void Shutdown() override;

    void PhotonCallService(bool bDispatchIncomingCommands);

    void PhotonSetConnectionState(bool bConnecting, bool bConnected);

    void PhotonSetCurrentHandler(UPTPhotonBaseHandler* Handler);

    bool PhotonGetPhotonIsConnecting();

    bool PhotonGetPhotonIsConnected();

private:

    UPROPERTY()
        UPTPhotonClient* PhotonClient;
    UPROPERTY()
        FString ServerAddress = "127.0.0.1:5055";
    UPROPERTY()
        FString ApplicationName = "MasterServer";
};
