// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomVehiclePhysics/VehicleMovementComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Pawn.h"
#include "BaseVehicle.generated.h"

UCLASS()
class CUSTOMVEHICLEPHYSICS_API ABaseVehicle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseVehicle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* VehicleMesh;

	UPROPERTY(EditAnywhere, Category = "Movement Properties")
	UVehicleMovementComponent* VehicleMovement;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	USceneComponent* Wheel1;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	USceneComponent* Wheel2;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	USceneComponent* Wheel3;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	USceneComponent* Wheel4;

	UPROPERTY(EditAnywhere, Category = "VehicleProperties")
		float VehicleMass;
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
