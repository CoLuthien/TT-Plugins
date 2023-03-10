
#pragma once

#include <CoreMinimal.h>
#include <Components/ActorComponent.h>

#include "Http.h"
#include "HttpModule.h"

#include "HttpReceiverComp.generated.h"

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class RESTRECEIVER_API UHttpReceiverComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UHttpReceiverComponent();

    UFUNCTION(BlueprintCallable)
    void SendRequest(FString const& URL, FString const& Verb, FString const& API);

    void OnResponseReceived(FHttpRequestPtr Request,
                            FHttpResponsePtr Response,
                            bool bWasSuccessful);

    UFUNCTION(BlueprintImplementableEvent)
    void RequestWriteBack();

private:
};
