// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeteroSpaceGameMode.h"
#include "HeteroSpacePlayerController.h"
#include "HeteroSpaceCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "HPushPawn.h"

AHeteroSpaceGameMode::AHeteroSpaceGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHeteroSpacePlayerController::StaticClass();
	isReversed = false;
}

void AHeteroSpaceGameMode::StartPlay()
{
	Super::StartPlay();
}

void AHeteroSpaceGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Copy"), Actors);
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	for (AActor* Actor : Actors)
	{
		SpawnParams.Template = Actor;
		UClass* actorClass = Actor->GetClass();
		FVector spawnLocation = FVector(0,10000,0);
		FRotator spawnRotation = Actor->GetActorRotation();
		AActor* spawned = GetWorld()->SpawnActor(actorClass, &spawnLocation, &spawnRotation ,SpawnParams);

		AHPushPawn* pushPawn = Cast<AHPushPawn>(Actor);
		if (pushPawn) 
		{
			pushPawn->copyPushPawn = Cast<AHPushPawn>(spawned);
		}
	}
}
