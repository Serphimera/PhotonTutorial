// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTGameInstance.h"


void UPTGameInstance::Init()
{
    PhotonClient = NewObject<UPTPhotonClient>();

    if (PhotonClient && PhotonClient->IsValidLowLevelFast(true))
    {
        PhotonClient->PhotonConnect(ServerAddress, ApplicationName);
    }
}

void UPTGameInstance::Shutdown()
{
    Super::Shutdown();
}

void UPTGameInstance::PhotonCallService(bool bDispatchIncomingCommands)
{
    if (PhotonClient && PhotonClient->IsValidLowLevelFast(true))
    {
        PhotonClient->PhotonCallServer(bDispatchIncomingCommands);
    }
}

void UPTGameInstance::PhotonSetConnectionState(bool bConnecting, bool bConnected)
{
    if (PhotonClient && PhotonClient->IsValidLowLevelFast(true))
    {
        PhotonClient->PhotonSetConnectionState(bConnecting, bConnected);
    }
}

void UPTGameInstance::PhotonSetCurrentHandler(UPTPhotonBaseHandler* Handler)
{
    if (Handler && Handler->IsValidLowLevelFast(true))
    {
        PhotonClient->PhotonSetCurrentHandler(Handler);
    }
}

bool UPTGameInstance::PhotonGetPhotonIsConnecting()
{
    return PhotonClient->PhotonGetIsConnecting();
}

bool UPTGameInstance::PhotonGetPhotonIsConnected()
{
    return PhotonClient->PhotonGetIsConnected();
}
