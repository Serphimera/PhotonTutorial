// Sebastian Kenter

#pragma once

#include "SlateWidgetStyleContainerBase.h"
#include "PTGlobalWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct PHOTONTUTORIAL_API FPTGlobalStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FPTGlobalStyle& GetDefault();

    UPROPERTY(EditAnywhere, Category = Appearance)
        FButtonStyle MenuButtonStyle;

    UPROPERTY(EditAnywhere, Category = Appearance)
        FTextBlockStyle MenuButtonTextStyle;

    UPROPERTY(EditAnywhere, Category = Appearance)
        FTextBlockStyle MenuTitleStyle;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UPTGlobalWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_UCLASS_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FPTGlobalStyle MenuStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &MenuStyle );
	}
};
