// Sebastian Kenter

#pragma once

#include "GameFramework/GameMode.h"
#include "PTLoginController.h"
#include "PTLoginHandler.h"
#include "PTLoginGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PHOTONTUTORIAL_API APTLoginGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

    virtual void BeginPlay() override;
	
    UPROPERTY()
        APTLoginController* Controller;

    UPROPERTY()
        UPTLoginHandler* Handler;
};
