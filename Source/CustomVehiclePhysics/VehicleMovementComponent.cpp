// Fill out your copyright notice in the Description page of Project Settings.

#include "VehicleMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

UVehicleMovementComponent::UVehicleMovementComponent()
{
	
}

void UVehicleMovementComponent::Accelerate(UInputComponent* VehicleInputComponent)
{
}

void UVehicleMovementComponent::AddUpwardImpulse()
{
	UKismetSystemLibrary::PrintString(this, "Adding Impulse", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	VehicleMesh->AddImpulse(FVector(0, 0, 10.0f));
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