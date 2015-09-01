// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTLoginController.h"


// Sets default values
APTLoginController::APTLoginController(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APTLoginController::BeginPlay()
{
	Super::BeginPlay();

    UWorld* World = GetWorld();

    if (World)
    {
        PTGameInstance = Cast<UPTGameInstance>(World->GetGameInstance());
    }

    FTimerHandle LoginControllerTimerHandle;

    GetWorldTimerManager().SetTimer(LoginControllerTimerHandle, this, &APTLoginController::PhotonService, 1.0f, true);
}

// Called every frame
void APTLoginController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void APTLoginController::PhotonService()
{
    if (PTGameInstance)
    {
        if (PTGameInstance->PhotonGetPhotonIsConnected() || PTGameInstance->PhotonGetPhotonIsConnecting())
        {
            PTGameInstance->PhotonCallService(true);
        }
    }
}