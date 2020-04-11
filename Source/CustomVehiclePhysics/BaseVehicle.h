// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomVehiclePhysics/VehicleMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "BaseVehicle.generated.h"

UCLASS()
class CUSTOMVEHICLEPHYSICS_API ABaseVehicle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseVehicle();

	UPROPERTY(EditAnywhere, Category="VehicleMeshComponent")
	UStaticMeshComponent* VehicleMesh;

	UVehicleMovementComponent* VehicleMovement;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ApplyUpwardImpulse();

};
