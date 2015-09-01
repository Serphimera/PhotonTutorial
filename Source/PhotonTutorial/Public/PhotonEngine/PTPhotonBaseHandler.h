// Sebastian Kenter

#pragma once

#include "Components/ActorComponent.h"
#include "PhotonImport.h"
#include "PTPhotonBaseHandler.generated.h"

using namespace ExitGames::Common;
using namespace ExitGames::Photon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHOTONTUTORIAL_API UPTPhotonBaseHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPTPhotonBaseHandler(const FObjectInitializer& ObjectInitialzer);

    virtual void HandleOnOperationResponse(const OperationResponse& operattionRespone);
    virtual void HandleOnStatusChanged(int statusCode);
    virtual void HandleOnEvent(const EventData& eventData);
    virtual void HandleDebugReturn(int debugLevel, const JString& string);
};
