// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterMovementComponent.h"

UMyCharacterMovementComponent::UMyCharacterMovementComponent(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	MaxAcceleration = 10000.f;
	BrakingFrictionFactor = 500.f;
	MaxStepHeight = 1.f;
	MaxWalkSpeed = 50.f;
	BrakingDecelerationFlying = 10000.f;
	bEnablePhysicsInteraction = false;
	bUseRVOAvoidance = true;
	AvoidanceConsiderationRadius = 25.f;
	AvoidanceWeight = 0.5f;

}

void UMyCharacterMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto CharacterForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	AIMoveVelocity = MoveVelocity;
	AIMoveIntention = MoveVelocity.GetSafeNormal();

	AIForwardThrow = FVector::DotProduct(AIMoveIntention, CharacterForward);

	AIRotationThrow = FVector::CrossProduct(CharacterForward, AIMoveIntention).Z;

	// .Z converts the cross product to a float so our turn right function can work.
}

//void UMyCharacterMovementComponent::RequestPathMove(const FVector& MoveInput)
//{
//	auto CharacterForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
//	AIMoveIntention = MoveInput;
//
//	AIForwardThrow = FVector::DotProduct(AIMoveIntention, CharacterForward);
//
//	AIRotationThrow = FVector::CrossProduct(CharacterForward, AIMoveIntention).Z;
//}