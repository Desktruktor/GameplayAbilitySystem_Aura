// Copyright Marco


#include "UI/WidgetController/AuraWidgetController.h"


//----------- Asi es como se construye un STRUCT para usar como blueprint step three--------
void UAuraWidgetController::SetWidgetParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadCastInitialValues()
{
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	
}
