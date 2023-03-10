
#include "HttpReceiverComp.h"

#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"


inline static FHttpModule* m_module = &FHttpModule::Get();
UHttpReceiverComponent::UHttpReceiverComponent() : Super()
{
}

void
UHttpReceiverComponent::SendRequest(FString const& URL, FString const& Verb, FString const& API)
{
    TSharedRef<IHttpRequest> Request = m_module->CreateRequest();
    Request->OnProcessRequestComplete().BindUObject(
        this, &UHttpReceiverComponent::OnResponseReceived);

    // This is the url on which to process the request

    Request->SetURL(URL + API);
    Request->SetVerb(Verb);

    Request->ProcessRequest();

    UE_LOG(LogTemp, Log, TEXT("HttpCall url : %s \t API : %s"), *URL, *API);
}

void
UHttpReceiverComponent::OnResponseReceived(FHttpRequestPtr Request,
                                           FHttpResponsePtr Response,
                                           bool bWasSuccessful)
{
    UE_LOG(LogTemp,
           Warning,
           TEXT("OnResponseReceived   url : %s\nrecv : %s"),
           *Request->GetURL(),
           *Response->GetContentAsString());

    // Create a pointer to hold the json serialized data
    TSharedPtr<FJsonObject> JsonObject;

    // Create a reader pointer to read the json data
    TSharedRef<TJsonReader<>> Reader =
        TJsonReaderFactory<>::Create(Response->GetContentAsString());

    // Deserialize the json data given Reader and the actual object to deserialize
    if (FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        // Get the value of the json object by field name
        FString recievedInt = JsonObject->GetStringField("total");

        UE_LOG(LogTemp, Log, TEXT("HTTP request result   customInt : %s"), *recievedInt);
    }
}
