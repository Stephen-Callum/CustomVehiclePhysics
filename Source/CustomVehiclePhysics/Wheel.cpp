// Fill out your copyright notice in the Description page of Project Settings.
// The point at which the suspension and wheel originate from.

#include "Wheel.h"
#include "CustomVehiclePhysics/VehicleMovementComponent.h"

// Sets default values for this component's properties
UWheel::UWheel()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWheel::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWheel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Call Suspension from VMC
	//VehicleMovement->Suspension(this);
}

