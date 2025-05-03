// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPPlayerController.h"
#include "CPPCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"

// Called to bind functionality to input
void ACPPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACPPPlayerController::Jump);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ACPPPlayerController::Interact);

	InputComponent->BindAxis("Move_Forward", this, &ACPPPlayerController::Move_Forward);
	InputComponent->BindAxis("Move_Right", this, &ACPPPlayerController::Move_Right);

	InputComponent->BindAxis("Turn", this, &ACPPPlayerController::Turn);
}

void ACPPPlayerController::Move_Forward(float Value)
{
	if (APawn* MyPawn = GetPawn())
	{
		MyPawn->AddMovementInput(MyPawn->GetActorForwardVector(), Value);
	}
}

void ACPPPlayerController::Move_Right(float Value)
{
	if (APawn* MyPawn = GetPawn())
	{
		MyPawn->AddMovementInput(MyPawn->GetActorRightVector(), Value);
	}
}

void ACPPPlayerController::Turn(float Value)
{
	AddYawInput(Value);
}

void ACPPPlayerController::Jump()
{
	if (ACharacter* MyCharacter = Cast<ACharacter>(GetPawn()))
	{
		MyCharacter->Jump();
	}
}

void ACPPPlayerController::Interact()
{
	if (ACPPCharacter* MyCharacter = Cast<ACPPCharacter>(GetPawn()))
	{
		MyCharacter->Interact();
	}
}


