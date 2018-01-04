// Fill out your copyright notice in the Description page of Project Settings.

#include "ThirdCharacter.h"


// Sets default values
AThirdCharacter::AThirdCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThirdCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThirdCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnCalculateDead();

}

// Called to bind functionality to input
void AThirdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Implement CalculateHealth
void AThirdCharacter::CalculateHealth(float Delta)
{
	Health -= Delta;
	OnCalculateDead();
}
//Implement CalculateDead
void AThirdCharacter::OnCalculateDead()
{
	if (Health <= 0)
	{
		isDead = true;
	}
	else
	{
		isDead = false;
	}
}
//Implement PostEditChangeProperty
#if WITH_EDITOR
void AThirdCharacter::PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent)
{
	isDead = false;
	Health = 100;
	Super::PostEditChangeProperty(PropertyChangedEvent);
		OnCalculateDead();
}
#endif