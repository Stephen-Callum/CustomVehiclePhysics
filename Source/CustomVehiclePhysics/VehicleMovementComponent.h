// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "Components/InputComponent.h"
#include "CustomVehiclePhysics/Wheel.h"
#include "VehicleMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMVEHICLEPHYSICS_API UVehicleMovementComponent : public UMovementComponent
{
	GENERATED_BODY()
	
		UVehicleMovementComponent();


public:
	UPROPERTY(EditAnywhere, Category = "Upward Force")
	float UpwardForce;
	
	UPROPERTY()
	UStaticMeshComponent* VehicleMesh;

	UFUNCTION()
	UStaticMeshComponent* GetVehicleMesh();

protected:

public:
	UFUNCTION()
	void AddUpwardImpulse();

	UFUNCTION()
	void SetVehicleMesh(UStaticMeshComponent * VehicleMeshRef);

	UFUNCTION()
	void Suspension(UWheel* Wheel);

};
