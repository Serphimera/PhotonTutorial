// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTPhotonClient.h"

UPTPhotonClient::UPTPhotonClient(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{

}

void UPTPhotonClient::PostInitProperties()
{
    Super::PostInitProperties();

    Listener = new PTPhotonListener();

    if (!Listener)
    {
        UE_LOG(PTNet, Error, TEXT("PhotonListener could not be created!"));
    }

    Peer = new PhotonPeer(*Listener, ConnectionProtocol::UDP);

    if (!Peer)
    {
        UE_LOG(PTNet, Error, TEXT("PhotonPeer could not be created!"));
    }

}

void UPTPhotonClient::PhotonConnect(FString ServerAddress, FString ApplicationName)
{
    if (Peer)
    {
        bPhotonIsConnecting = Peer->connect(*ServerAddress, reinterpret_cast<nByte*>(TCHAR_TO_UTF8(*ApplicationName)));
    }
}

void UPTPhotonClient::PhotonDisconnect()
{
    if (Peer && bPhotonIsConnected == true)
    {
        Peer->disconnect();
    }
}

void UPTPhotonClient::PhotonCallServer(bool bDispatchIncomingCommands)
{
    if (Peer && (bPhotonIsConnected || bPhotonIsConnecting))
    {
        Peer->service(bDispatchIncomingCommands);
    }
}

void UPTPhotonClient::PhotonOperationRequest(nByte OperationCode, TMap<int, FString> Parameters)
{
    OperationRequestParameters parameters;

    for (auto It = Parameters.CreateConstIterator(); It; ++It)
    {
        parameters.put(It.Key(), ValueObject<JString>(*It.Value()));
    }

    OperationRequest request(OperationCode, parameters);

    Peer->opCustom(request, true, 0, false);

}

void UPTPhotonClient::PhotonSetConnectionState(bool bPhotonConnected, bool bPhotonConnecting)
{
    bPhotonIsConnecting = bPhotonConnecting;
    bPhotonIsConnected = bPhotonConnected;
}

void UPTPhotonClient::PhotonSetCurrentHandler(UPTPhotonBaseHandler* Handler)
{
    if (Handler && Handler->IsValidLowLevelFast(true))
    {
        Listener->setCurrentHandler(Handler);
    }
}

int UPTPhotonClient::PhotonGetPeerState()
{
    if (Peer)
    {
        return Peer->getPeerState();
    }

    return NULL;

}

bool UPTPhotonClient::PhotonGetIsConnecting()
{
    return bPhotonIsConnecting;
}

bool UPTPhotonClient::PhotonGetIsConnected()
{
    return bPhotonIsConnected;
}
