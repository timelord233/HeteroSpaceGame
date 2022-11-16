// Fill out your copyright notice in the Description page of Project Settings.


#include "HCameraActor.h"
#include "HeteroSpaceCharacter.h"
#include "Camera/CameraComponent.h"
#include "HeteroSpaceGameMode.h"

AHCameraActor::AHCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHCameraActor::BeginPlay()
{
	Super::BeginPlay();
	AHeteroSpaceCharacter* player = Cast<AHeteroSpaceCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (player) 
	{
		copyCamera = player->GetTopDownCameraComponent();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No Player!"));
	}
}

void AHCameraActor::Tick(float DeltaSeconds)
{
	AHeteroSpaceGameMode* GM = Cast<AHeteroSpaceGameMode>(GetWorld()->GetAuthGameMode());
	if (GM) 
	{
		if (copyCamera && GM->isReversed)
		{
			FTransform transform = copyCamera->GetComponentTransform();
			FVector location = transform.GetLocation();
			location.Y -= 10000;
			transform.SetLocation(location);
			this->SetActorTransform(transform);
		}
		else
		{
			FTransform transform = copyCamera->GetComponentTransform();
			FVector location = transform.GetLocation();
			location.Y += 10000;
			transform.SetLocation(location);
			this->SetActorTransform(transform);
		}
	}

}


