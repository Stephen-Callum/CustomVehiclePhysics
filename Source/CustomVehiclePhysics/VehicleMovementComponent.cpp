// Fill out your copyright notice in the Description page of Project Settings.

#include "VehicleMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

UVehicleMovementComponent::UVehicleMovementComponent()
{
	
}

void UVehicleMovementComponent::SetSuspension(UInputComponent* VehicleInputComponent)
{
	// Raycast to the ground
	// If DistanceToGround <= SuspensionHeight
		// ApplyForce Upwards (direction of raycast)
}

void UVehicleMovementComponent::AddUpwardImpulse()
{
	//float VehicleMass = VehicleMesh->GetMass();
	if (VehicleMesh)
	{
		UKismetSystemLibrary::PrintString(this, "Adding upward Impulse to Mesh", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));

	}
	
	//GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + FVector(100, 100, 100));
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