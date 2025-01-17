// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION_03_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float reach;

	UPhysicsHandleComponent *physics_handle = nullptr;

	UInputComponent *input_component = nullptr;

	void Grab();
	void Release();
	
	void SetupInputComponent();
	void FindPhysicsHandleComponent();

	FHitResult GetFirstPhysicsComponentWithinReach();

	FVector GetReachLineStart();
	FVector GetReachLineEnd();

};
