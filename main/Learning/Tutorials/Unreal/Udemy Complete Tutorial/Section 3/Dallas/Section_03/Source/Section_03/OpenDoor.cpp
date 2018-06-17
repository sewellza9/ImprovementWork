// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"


#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	if (!pressure_plate)
	{
		UE_LOG(LogTemp, Error, TEXT("No Pressure Plate on %s"), *(GetOwner()->GetName()))
	}

	owner = GetOwner();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnPlate() > trigger_weight)
	{
		on_open.Broadcast();
	}
	else
	{
		on_close.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float total_mass = 0.0f;

	TArray<AActor *> overlapping_actors;
	if (!pressure_plate) { return -1.0f; }
	pressure_plate->GetOverlappingActors(OUT overlapping_actors);

	for(const auto* actor : overlapping_actors)
	{
		total_mass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("Adding Mass: %f"), actor->FindComponentByClass<UPrimitiveComponent>()->GetMass())
	}
	
	if (total_mass != 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Total Mass: %f"), total_mass)
	}
	return total_mass;
}

