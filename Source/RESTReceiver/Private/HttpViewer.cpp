
#include "HttpViewer.h"
#include <Components/TextBlock.h>

void UHttpViewer::NativeConstruct()
{
    Super::NativeConstruct();


    if (m_text)
    {
        m_text->SetText(FText::FromString(TEXT("Http Request goes on here")));
    }
}