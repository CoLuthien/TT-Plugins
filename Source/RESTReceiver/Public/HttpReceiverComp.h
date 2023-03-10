
#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>
#include <GameFramework/Actor.h>

#include "Http.h"
#include "HttpModule.h"

#include "HttpReceiverComp.generated.h"

UCLASS(Blueprintable, BlueprintType)
class RESTRECEIVER_API AHttpReceiver : public AActor
{
    GENERATED_BODY()
public:
    AHttpReceiver();

    UFUNCTION(BlueprintCallable)
    void SendRequest(FString const& URL, FString const& Verb, FString const& API);


    void OnResponseReceived(FHttpRequestPtr Request,
                            FHttpResponsePtr Response,
                            bool bWasSuccessful);

    UFUNCTION(BlueprintImplementableEvent)
    void RequestWriteBack(FString const& Result);

private:
};
