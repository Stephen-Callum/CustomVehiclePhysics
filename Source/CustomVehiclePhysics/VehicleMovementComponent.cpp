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
}

void UVehicleMovementComponent::AddUpwardImpulse()
{
	float VehicleMass = VehicleMesh->GetMass();
	float NormalisedMagnitude = UKismetMathLibrary::NormalizeToRange(FMath::FRandRange(-1, 1) * VehicleMass, 0, 1);
	UKismetSystemLibrary::PrintString(this, "Adding upward Impulse to Mesh", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	VehicleMesh->AddImpulse(FVector(FMath::FRandRange(-1, 1), FMath::FRandRange(-1, 1), UpwardForce * VehicleMass/10), "NAME_None", true);
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