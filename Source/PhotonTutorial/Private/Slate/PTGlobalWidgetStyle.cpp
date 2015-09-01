// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTGlobalWidgetStyle.h"

const FName FPTGlobalStyle::TypeName(TEXT("FPTGlobalStyle"));

const FPTGlobalStyle& FPTGlobalStyle::GetDefault()
{
	static FPTGlobalStyle Default;
	return Default;
}

void FPTGlobalStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

UPTGlobalWidgetStyle::UPTGlobalWidgetStyle(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{

}