// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperCharacterOverride.h"
#include "MyCharacterMovementComponent.h"


APaperCharacterOverride::APaperCharacterOverride(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APaperCharacterOverride::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	MyCharacterMovementComponent = Cast<UMyCharacterMovementComponent>(Super::GetMovementComponent());
}