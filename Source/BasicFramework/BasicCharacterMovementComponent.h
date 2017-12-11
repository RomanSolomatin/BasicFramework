// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BasicCharacterMovementComponent.generated.h"

/**
 * @author Giulio_M
 *
 *
 */

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EBasicCharacterCustomMovementMode : uint8
{
	CMOVE_LADDER 		UMETA(DisplayName = "Ladder"),
};

UCLASS()
class BASICFRAMEWORK_API UBasicCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

protected:

	void OnMovementModeChanged(EMovementMode prevMovement, uint8 prevCustomMovement) override;
	void PhysCustom(float deltaTime, int32 Iterations) override;

	virtual void PhysCustomLadder(float deltaTime, int32 Iterations);

public:

	UFUNCTION(BlueprintCallable)
	void SetMovementMode(EMovementMode NewMovementMode, uint8 NewCustomMode) override;

	UFUNCTION(BlueprintCallable)
	EBasicCharacterCustomMovementMode GetCustomMovementMode() { return static_cast<EBasicCharacterCustomMovementMode>(CustomMovementMode); }
	
	
};
