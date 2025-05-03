// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "CPPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTGAME_API ACPPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;

private:
	void Move_Forward(float Value);
	void Move_Right(float Value);
	void Turn(float Value);
	void Jump();
};
