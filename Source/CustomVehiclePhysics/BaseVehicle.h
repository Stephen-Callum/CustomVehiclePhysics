// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomVehiclePhysics/VehicleMovementComponent.h"
#include "CustomVehiclePhysics/Wheel.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "BaseVehicle.generated.h"

UCLASS()
class CUSTOMVEHICLEPHYSICS_API ABaseVehicle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseVehicle();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* VehicleMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement Properties")
	UVehicleMovementComponent* VehicleMovement;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	UWheel* Wheel1;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	UWheel* Wheel2;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	UWheel* Wheel3;

	UPROPERTY(EditAnywhere, Category = "Wheels")
	UWheel* Wheel4;

	UPROPERTY(EditAnywhere, Category = "VehicleCamera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "VehicleCamera")
	UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void CheckMovementComponent();

	UFUNCTION()
	void ApplyUpwardImpulse();

};
