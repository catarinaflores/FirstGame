// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPDoorInterface.generated.h"


class AActor;


// This class does not need to be modified.
UINTERFACE(Blueprintable)
class FIRSTGAME_API UCPPDoorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FIRSTGAME_API ICPPDoorInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interaction")
	void Interact(AActor* Interactor);
};
