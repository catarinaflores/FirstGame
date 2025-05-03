// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCharacter.h"
#include "Camera/CameraComponent.h"
// boundbox
#include "Components/CapsuleComponent.h"
#include "DoorInterface.h"

// Sets default values
ACPPCharacter::ACPPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComp->SetupAttachment(GetCapsuleComponent()); // Attach to the capsule

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ACPPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPPCharacter::Interact()
{
	TArray<AActor*> OverlappingActors;
	GetCapsuleComponent()->GetOverlappingActors(OverlappingActors);
	UE_LOG(LogTemp, Log, TEXT("Number of overlapping actors: %d"), OverlappingActors.Num());
	for (AActor* Actor : OverlappingActors)
	{
		if (!Actor)
			continue;
		if (Actor->GetClass()->ImplementsInterface(UDoorInterface::StaticClass()))
		{
			UE_LOG(LogTemp, Log, TEXT("Interacting with: %s"), *Actor->GetName());
			UE_LOG(LogTemp, Log, TEXT("Interact called by: %s"), *GetName());
			UE_LOG(LogTemp, Warning, TEXT("Interact() called on %s at frame %d"), *GetName(), GFrameCounter);
			UE_LOG(LogTemp, Warning, TEXT("Did This call Twice? Owning Actor: %s | Component Name: %s"), *GetOwner()->GetName(), *GetName());
			//IDoorInterface::Execute_OpenDoor(Actor, this);
			break;
		}
	}
}
