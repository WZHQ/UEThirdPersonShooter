// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdCharacter.generated.h"

UCLASS()
class THIRDSHOOTGAME_API AThirdCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		bool isDead = false;
	UFUNCTION(BlueprintCallable,Category="Base Character")
	virtual void OnCalculateDead();
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float delta);
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent&PropertyChangedEvent)
		override;
#endif
	
};
