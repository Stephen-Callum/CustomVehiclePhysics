// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseVehicle.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseVehicle::ABaseVehicle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create VehicleMesh
	VehicleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleMesh"));
	VehicleMesh->SetSimulatePhysics(true);
	RootComponent = VehicleMesh;

	// Add Vehicle Movement Component
	VehicleMovement = CreateDefaultSubobject<UVehicleMovementComponent>("VehicleMovement");
	VehicleMovement->SetVehicleMesh(VehicleMesh);

	// Movement
	
	// Setup player input

}

// Called when the game starts or when spawned
void ABaseVehicle::BeginPlay()
{
	Super::BeginPlay();
	// Check if mesh is valid
	if (VehicleMovement->GetVehicleMesh())
	{
		UKismetSystemLibrary::PrintString(this, "Vehicle Mesh Setup", true, true, FLinearColor(0.0f, 0.6f, 1.0f, 1.0f));
	}
}

// Called every frame
void ABaseVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//check(PlayerInputComponent);

	PlayerInputComponent->BindAction("ForceUp", IE_Pressed, this, &ABaseVehicle::ApplyUpwardImpulse);
}

void ABaseVehicle::ApplyUpwardImpulse()
{
	VehicleMovement->AddUpwardImpulse();
}

