// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "HCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class HETEROSPACE_API AHCameraActor : public ACameraActor
{
	GENERATED_BODY()
	
public:
	AHCameraActor();
	
	virtual void BeginPlay() override;
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

private:
	class UCameraComponent* copyCamera;

};
