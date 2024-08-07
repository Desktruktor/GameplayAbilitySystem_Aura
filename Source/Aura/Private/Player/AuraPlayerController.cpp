// Copyright Marco


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Implementacion de Aura Context
	check(AuraContext);		//checamos si existe este contexto
	
	// Esta clase permite gestionar y configurar mappings de entrada y contextos de entrada de manera más dinámica y eficiente
	//-->El ULocalPlayer Representa a un jugador en el contexto de una sesión local (es decir, un jugador que está usando el juego en una sola máquina y no a través de red)
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()); 
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0); //Se lo agregamos al Contexto de AuraContext

	
	bShowMouseCursor = true; // Mostramos Mouse en pantalla
	DefaultMouseCursor = EMouseCursor::Default; // Utilizamos el Mous por defecto

	
	// Configurar el modo de entrada que permite tanto la interacción con la UI como el control del jugador.
	FInputModeGameAndUI InputModeData;		
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
