// Sebastian Kenter

#pragma once

#include "PhotonEngine/PTPhotonBaseHandler.h"
#include "PTGameInstance.h"
#include "PTLoginHandler.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHOTONTUTORIAL_API UPTLoginHandler : public UPTPhotonBaseHandler
{
	GENERATED_BODY()
	
public:

    virtual void InitializeComponent();

    virtual void HandleOnOperationResponse(const OperationResponse& operattionRespone);

    virtual void HandleOnStatusChanged(int statusCode) override;

    virtual void HandleOnEvent(const EventData& eventData) override;

    virtual void HandleDebugReturn(int debugLevel, const JString& string) override;

    UPROPERTY()
        UPTGameInstance* PTGameInstance;
};
