// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTLoginHandler.h"

void UPTLoginHandler::InitializeComponent()
{
    PTGameInstance = Cast<UPTGameInstance>(this->GetOwner()->GetGameInstance());

    PTGameInstance->PhotonSetCurrentHandler(this);

    Super::InitializeComponent();
}

void UPTLoginHandler::HandleOnOperationResponse(const OperationResponse& operattionRespone)
{
    // Will be implemented later on
}

void UPTLoginHandler::HandleOnStatusChanged(int statusCode)
{
    Super::HandleOnStatusChanged(statusCode);
}

void UPTLoginHandler::HandleOnEvent(const EventData& eventData)
{
    // Will be implemented later on
}

void UPTLoginHandler::HandleDebugReturn(int debugLevel, const JString& string)
{
    Super::HandleDebugReturn(debugLevel, string);
}