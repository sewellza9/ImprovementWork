// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector view_point_pos;
	FRotator view_point_rot;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT view_point_pos, OUT view_point_rot);
/*
	UE_LOG(LogTemp, Warning, TEXT("Player Pos: %s"), *(view_point_pos.ToString()))
	UE_LOG(LogTemp, Warning, TEXT("Player View: %s"), *(view_point_rot.ToString()))
*/

	FVector player_forward = view_point_rot.Vector();
	player_forward.Normalize();

	DrawDebugLine(GetWorld(), view_point_pos, view_point_pos + player_forward * reach, FColor(0, 255, 0), false, -1.0f, 0.0f, 10.0f);

}

