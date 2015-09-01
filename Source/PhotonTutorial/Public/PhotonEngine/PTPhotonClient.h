// Sebastian Kenter

#pragma once

#include "Object.h"
#include "PTPhotonListener.h"
#include "PTPhotonBaseHandler.h"
#include "PTPhotonClient.generated.h"

/**
 * 
 */
UCLASS()
class PHOTONTUTORIAL_API UPTPhotonClient : public UObject
{
	GENERATED_BODY()
	
public:

    UPTPhotonClient(const FObjectInitializer& ObjectInitializer);

    virtual void PostInitProperties() override;

    void PhotonConnect(FString ServerAddress, FString ApplicationName);

    void PhotonDisconnect();

    void PhotonCallServer(bool bDispatchIncomingCommands);
	
    void PhotonOperationRequest(nByte OperationCode, TMap<int, FString> Parameters);

    void PhotonSetConnectionState(bool bPhotonConnected, bool bPhotonConnecting);

    void PhotonSetCurrentHandler(UPTPhotonBaseHandler* Handler);

    int PhotonGetPeerState();

    bool PhotonGetIsConnecting();

    bool PhotonGetIsConnected();

private:

    bool bPhotonIsConnecting = false;
    bool bPhotonIsConnected = false;

    PTPhotonListener* Listener;
    PhotonPeer* Peer;
};
