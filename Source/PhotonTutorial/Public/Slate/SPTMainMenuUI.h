// Sebastian Kenter

#pragma once

#include "SlateBasics.h"
#include "PTHUD.h"
#include "PTGlobalWidgetStyle.h"
#include "PTMenuStyles.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class PHOTONTUTORIAL_API SPTMainMenuUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPTMainMenuUI)
	{}
    SLATE_ARGUMENT(TWeakObjectPtr<class APTHUD>, MainMenuHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

    FReply LogInClicked();
    FReply CancelClicked();

    TWeakObjectPtr<class APTHUD> MainMenuHUD;

    const struct FPTGlobalStyle* MenuStyle;
};
