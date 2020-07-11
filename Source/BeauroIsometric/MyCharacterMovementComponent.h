// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BEAUROISOMETRIC_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()



public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Throws")
		FVector  AIMoveIntention;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Throws")
	float AIForwardThrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Throws")
	float AIRotationThrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Throws")
	FVector AIMoveVelocity;

		UFUNCTION(BlueprintCallable, Category = "MovementRequest")
		virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

		//UFUNCTION(BlueprintCallable, Category = "MovementRequest")
		//	virtual void RequestPathMove(const FVector& MoveInput) override;
};
