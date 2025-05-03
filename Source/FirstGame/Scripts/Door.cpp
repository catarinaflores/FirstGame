#include "Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);

	// Create and initialize the box container
	BoxContainer = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxContainer"));
	BoxContainer->SetupAttachment(RootComponent); // Attach to the root or another component
	BoxContainer->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f)); // Set the size of the box
	BoxContainer->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // Set collision settings
	BoxContainer->SetCollisionResponseToAllChannels(ECR_Overlap); // Set response to overlap
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	// Bind the correct overlap events
	// BoxContainer->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnOverlapBegin);
	// BoxContainer->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnOverlapEnd);
}



// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

}

void ADoor::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacted"));
}

// Overlap begin event
void ADoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin with: %s"), *OtherActor->GetName());
}

// Overlap end event
void ADoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap End with: %s"), *OtherActor->GetName());
}