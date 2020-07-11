// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "MyCharacterMovementComponent.h"
#include "PaperCharacterOverride.generated.h"

/**
 * 
 */
UCLASS()
class BEAUROISOMETRIC_API APaperCharacterOverride : public APaperCharacter
{
	GENERATED_BODY()

public:
	   	APaperCharacterOverride(const FObjectInitializer& ObjectInitializer);
	
		UFUNCTION(BlueprintCallable, Category = "Movement")
		FORCEINLINE class UMyCharacterMovementComponent * GetMyMovementComponent() const { return MyCharacterMovementComponent; }

	virtual void PostInitializeComponents() override;

private:
	UMyCharacterMovementComponent* MyCharacterMovementComponent;
};
