// Fill out your copyright notice in the Description page of Project Settings.

#include "VehicleMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"

UVehicleMovementComponent::UVehicleMovementComponent()
{
	
}

void UVehicleMovementComponent::Suspension(UWheel* Wheel)
{
	// Raycast to the ground
	// Hit contains information about what the raycast hit
	FHitResult Hit;

	// The length of the ray in units.
	float RayLength = Wheel->SuspensionHeight;

	// Raycast origin
	FVector StartLocation = Wheel->GetComponentLocation();

	// Raycast end location
	FVector EndLocation = StartLocation + (VehicleMesh->GetUpVector() * -1 * RayLength);

	// Collion parameters
	FCollisionQueryParams CollisionParameters;
	CollisionParameters.AddIgnoredActor(GetOwner());

	// Perform line trace
	// EcollisionChannel used in order to determine what we are looking for from the raycast
	GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_WorldDynamic, CollisionParameters);

	// Draw debug line
	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1, 0, 1.f);

	// If DistanceToGround <= SuspensionHeight
		// ApplyForce Upwards (direction of raycast)
}

void UVehicleMovementComponent::AddUpwardImpulse()
{
	if (VehicleMesh)
	{
		UKismetSystemLibrary::PrintString(this, "Adding upward Impulse", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
		VehicleMesh->AddImpulseAtLocation(FVector(0, 0, 500 * VehicleMesh->GetMass()), FVector(0, 0, -70) + VehicleMesh->GetComponentLocation());
	}
}

void UVehicleMovementComponent::SetVehicleMesh(UStaticMeshComponent* VehicleMeshRef)
{
	if (VehicleMeshRef)
	{
		VehicleMesh = VehicleMeshRef;
	}
}

UStaticMeshComponent* UVehicleMovementComponent::GetVehicleMesh()
{
	return VehicleMesh;
}