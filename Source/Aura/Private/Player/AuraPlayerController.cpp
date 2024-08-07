// Copyright Marco


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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
	// El ULocalPlayer Representa a un jugador en el contexto de una sesión local (es decir, un jugador que está usando el juego en una sola máquina y no a través de red)
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

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())	
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}

	
}
