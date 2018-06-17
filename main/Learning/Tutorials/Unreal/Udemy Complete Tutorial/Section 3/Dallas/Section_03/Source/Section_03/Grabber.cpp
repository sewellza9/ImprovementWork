// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();

	SetupInputComponent();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!physics_handle) { return; }
	if(physics_handle->GrabbedComponent)
	{
		physics_handle->SetTargetLocation(GetReachLineEnd());
	}
}


void UGrabber::Grab()
{
	FHitResult hit_result  = GetFirstPhysicsComponentWithinReach();
	UPrimitiveComponent *component_to_grab = hit_result.GetComponent();

	if (!physics_handle) { return; }
	if (hit_result.GetActor())
	{
		physics_handle->GrabComponent(component_to_grab, NAME_None, component_to_grab->GetOwner()->GetActorLocation(), true);
	}
}


void UGrabber::Release()
{
	if (!physics_handle) { return; }
	physics_handle->ReleaseComponent();
}


void UGrabber::SetupInputComponent()
{
	input_component = GetOwner()->FindComponentByClass<UInputComponent>();
	if (input_component)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input Component found on %s"), *(GetOwner()->GetName()));
		input_component->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		input_component->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Input Component on %s"), *(GetOwner()->GetName()))
	}
}


void UGrabber::FindPhysicsHandleComponent()
{
	physics_handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (physics_handle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No Physics Handle Component on %s"), *(GetOwner()->GetName()))
	}
}

FHitResult UGrabber::GetFirstPhysicsComponentWithinReach()
{
	FVector line_trace_start = GetReachLineStart();
	FVector line_trace_end = GetReachLineEnd();
	DrawDebugLine(GetWorld(), line_trace_start, line_trace_end, FColor(0, 255, 0), false, -1.0f, 0.0f, 10.0f);

	FHitResult hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT hit,
		line_trace_start,
		line_trace_end,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
	);

	AActor* hit_actor = hit.GetActor();
	if (hit_actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), (*hit_actor->GetName()))
	}
	return hit;
}


FVector UGrabber::GetReachLineStart()
{
	FVector view_point_pos;
	FRotator view_point_rot;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT view_point_pos, OUT view_point_rot);

	FVector player_forward = view_point_rot.Vector();
	player_forward.Normalize();

	return view_point_pos;
}


FVector UGrabber::GetReachLineEnd()
{
	FVector view_point_pos;
	FRotator view_point_rot;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT view_point_pos, OUT view_point_rot);

	FVector player_forward = view_point_rot.Vector();
	player_forward.Normalize();

	return view_point_pos + player_forward * reach;
}
