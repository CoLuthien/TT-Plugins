
#pragma once

#include <CoreMinimal.h>
#include <Blueprint/UserWidget.h>
#include "HttpViewer.generated.h"


UCLASS(Abstract, Blueprintable)
class RESTRECEIVER_API UHttpViewer : public UUserWidget 
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

protected:
    UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
    class UTextBlock* m_text;
};