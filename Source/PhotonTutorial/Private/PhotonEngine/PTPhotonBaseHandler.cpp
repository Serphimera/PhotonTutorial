// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTGameInstance.h"
#include "PTPhotonBaseHandler.h"

UPTPhotonBaseHandler::UPTPhotonBaseHandler(const FObjectInitializer& ObjectInitialzer)
    :Super(ObjectInitialzer)
{
    bWantsInitializeComponent = true;
    bWantsBeginPlay = true;
    bAutoActivate = true;
    bAutoRegister = true;
    PrimaryComponentTick.bCanEverTick = false;
}

void UPTPhotonBaseHandler::HandleOnOperationResponse(const OperationResponse& operattionRespone)
{
    // This will be implemented in the specific handler
}

void UPTPhotonBaseHandler::HandleOnStatusChanged(int statusCode)
{
    switch (statusCode)
    {
    case StatusCode::EXCEPTION_ON_CONNECT:
    {
        // PhotonSetConnectionState(bool bConnected, bool bConnecting)
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Error, TEXT("The PhotonPeer excountered an exception connecting to the server. Perhaps server down!"));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The PhotonPeer excountered an exception connecting to the server. Perhaps server down!"));
        }
    } break;
    case StatusCode::CONNECT:
    {
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(true, false);
        UE_LOG(PTNet, Log, TEXT("The PhotonPerr is connected to the server."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("The PhotonPerr is connected to the server."));
        }
    } break; case StatusCode::DISCONNECT:
    {
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Log, TEXT("The PhotonPeer just disconnected from the server."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer just disconnected from the server."));
        }
    } break; case StatusCode::EXCEPTION:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Error, TEXT("The PhotonPeer encountered an exception and will disconnect from the server!"));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The PhotonPeer encountered an exception and will disconnect from the server!"));
        }
    } break; case StatusCode::QUEUE_OUTGOING_RELIABLE_WARNING:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("The PhotonPeer outgoing reliable queue is filling up - call service more often."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer outgoing reliable queue is filling up - call service more often."));
        }
    } break; case StatusCode::QUEUE_OUTGOING_UNRELIABLE_WARNING:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("The PhotonPeer outgoing unreliable queue is filling up - call service more often."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer outgoing unreliable queue is filling up - call service more often."));
        }
    } break; case StatusCode::QUEUE_OUTGOING_ACKS_WARNING:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("The PhotonPeer outgoing acks queue is filling up - call service more often."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer outgoing acks queue is filling up - call service more often."));
        }
    } break; case StatusCode::QUEUE_INCOMING_RELIABLE_WARNING:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("The PhotonPeer incoming reliable queue is filling up - call service more often."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer incoming reliable queue is filling up - call service more often."));
        }
    } break; case StatusCode::QUEUE_INCOMING_UNRELIABLE_WARNING:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("The PhotonPeer incoming unreliable queue is filling up - call service more often."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer incoming unreliable queue is filling up - call service more often."));
        }
    } break; case StatusCode::QUEUE_SENT_WARNING:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("The PhotonPeer's sent queue is fiiling up. Check why the server does not send acks for reliable commands!"));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("The PhotonPeer's sent queue is fiiling up. Check why the server does not send acks for reliable commands!"));
        }
    } break; case StatusCode::SEND_ERROR:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Error, TEXT("Sending command failed. Either not connected, or the requested channel is bigger than the number of initialized channels."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Sending command failed. Either not connected, or the requested channel is bigger than the number of initialized channels."));
        }
    } break; case StatusCode::INTERNAL_RECEIVE_EXCEPTION:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Error, TEXT("Exception, if a server cannot be connected. The server does not respond. Try again later."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Exception, if a server cannot be connected. The server does not respond. Try again later."));
        }
    } break; case StatusCode::TIMEOUT_DISCONNECT:
    {
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("Disconnected due to a timeout (client receives no longer acks from the server!"));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnected due to a timeout (client receives no longer acks from the server!"));
        }
    } break; case StatusCode::DISCONNECT_BY_SERVER:
    {
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("Disconnected due to a timeout (received a disconnect command from the server. Server missed acks from the client)!"));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnected due to a timeout (received a disconnect command from the server. Server missed acks from the client)!"));
        }
    } break; case StatusCode::DISCONNECT_BY_SERVER_LOGIC:
    {
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("Disconnect by server logic - received a disconnect command."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnect by server logic - received a disconnect command."));
        }
    } break; case StatusCode::DISCONNECT_BY_SERVER_USER_LIMIT:
    {
        Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Warning, TEXT("Disconnect due to server user limit reached."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Disconnect due to server user limit reached."));
        }
    } break; case StatusCode::ENCRYPTION_ESTABLISHED:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Log, TEXT("The encryption system setup successfully."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("The encryption system setup successfully."));
        }
    } break; case StatusCode::ENCRYPTION_FAILED_TO_ESTABLISH:
    {
        //Cast<UPTGameInstance>(GetWorld()->GetGameInstance())->PhotonSetConnectionState(false, false);
        UE_LOG(PTNet, Error, TEXT("The encryption system could not be setup successfully."));
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The encryption system could not be setup successfully."));
        }
    } break;
    }
}

void UPTPhotonBaseHandler::HandleOnEvent(const EventData& eventData)
{
    // This will be implemented in the specific handler
}

void UPTPhotonBaseHandler::HandleDebugReturn(int debugLevel, const JString& string)
{
#if defined(UE_BUILD_DEBUG) || defined(UE_BUILD_DEVELOPMENT)
    switch (debugLevel)
    {
    case DebugLevel::ERRORS: UE_LOG(PTNet, Error, TEXT("Received DebugMessage from the Server: %"), string.cstr()); break;
    case DebugLevel::WARNINGS: UE_LOG(PTNet, Warning, TEXT("Received DebugMessage from the Server: %"), string.cstr()); break;
    case DebugLevel::INFO: UE_LOG(PTNet, Log, TEXT("Received DebugMessage from the Server: %"), string.cstr()); break;
    case DebugLevel::ALL: UE_LOG(PTNet, Log, TEXT("Received DebugMessage from the Server: %"), string.cstr()); break;
    }
#endif
}