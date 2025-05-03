// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPDoorInterface.h"
#include "CPPDoorActor.generated.h"

UCLASS()
class FIRSTGAME_API ACPPDoorActor : public AActor, public ICPPDoorInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPDoorActor();

	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
