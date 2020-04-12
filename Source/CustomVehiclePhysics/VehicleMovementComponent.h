// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "Components/InputComponent.h"
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
	
	UStaticMeshComponent* VehicleMesh;
	UStaticMeshComponent* GetVehicleMesh();

protected:

public:
	void AddUpwardImpulse();
	void SetVehicleMesh(UStaticMeshComponent * VehicleMesh);
	void SetSuspension(UInputComponent * VehicleInputComponent);

};
