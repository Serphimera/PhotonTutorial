// Sebastian Kenter

#include "PhotonTutorial.h"
#include "SPTMainMenuUI.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPTMainMenuUI::Construct(const FArguments& InArgs)
{
    MainMenuHUD = InArgs._MainMenuHUD;

    MenuStyle = &PTMenuStyles::Get().GetWidgetStyle<FPTGlobalStyle>("Global");

	ChildSlot
	[
        SNew(SOverlay)
        +SOverlay::Slot()
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Top)
        [
            SNew(STextBlock)
            .TextStyle(&MenuStyle->MenuTitleStyle)
            .Text(FText::FromString("Main Menu"))
        ]
        +SOverlay::Slot()
            .HAlign(HAlign_Center)
            .VAlign(VAlign_Bottom)
            [
                SNew(SVerticalBox)
                +SVerticalBox::Slot()
                [
                    SNew(SButton)
                    .ButtonStyle(&MenuStyle->MenuButtonStyle)
                    .TextStyle(&MenuStyle->MenuButtonTextStyle)
                    .Text(FText::FromString("Login"))
                    .OnClicked(this, &SPTMainMenuUI::LogInClicked)
                ]
                +SVerticalBox::Slot()
                [
                    SNew(SButton)
                    .ButtonStyle(&MenuStyle->MenuButtonStyle)
                    .TextStyle(&MenuStyle->MenuButtonTextStyle)
                    .Text(FText::FromString("Cancel"))
                    .OnClicked(this, &SPTMainMenuUI::CancelClicked)
                ]
            ]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SPTMainMenuUI::LogInClicked()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("LogIn clicked"));
    }

    return FReply::Handled();
}

FReply SPTMainMenuUI::CancelClicked()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Cancel clicked"));
    }

    return FReply::Handled();
}