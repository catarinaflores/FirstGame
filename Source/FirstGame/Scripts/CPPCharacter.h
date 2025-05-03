#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DoorInterface.h"

#include "CPPCharacter.generated.h"

UCLASS()
class FIRSTGAME_API ACPPCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;

public:
	// Sets default values for this character's properties
	ACPPCharacter();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void OnInteract();
	UPROPERTY(BlueprintReadWrite)
	AActor* OverlappingActor;
};
