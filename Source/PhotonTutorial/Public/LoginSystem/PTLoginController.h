// Sebastian Kenter

#pragma once

#include "GameFramework/Actor.h"
#include "PTGameInstance.h"
#include "PTLoginHandler.h"
#include "PTLoginController.generated.h"

UCLASS()
class PHOTONTUTORIAL_API APTLoginController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APTLoginController(const FObjectInitializer& ObjectiInitialzer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    void PhotonService();

    UPTGameInstance* PTGameInstance;
};
