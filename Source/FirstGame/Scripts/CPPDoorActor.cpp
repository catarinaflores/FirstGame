// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPDoorActor.h"

// Sets default values
ACPPDoorActor::ACPPDoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACPPDoorActor::Interact_Implementation(AActor* Interactor)
{
	ICPPDoorInterface::Execute_Interact(this, Interactor);

	UE_LOG(LogTemp, Warning, TEXT("Door Interacted With"), *GetNameSafe(Interactor));
}

// Called when the game starts or when spawned
void ACPPDoorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPDoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

