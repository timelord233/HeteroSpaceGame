// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HeteroSpaceGameMode.generated.h"

UCLASS(minimalapi)
class AHeteroSpaceGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHeteroSpaceGameMode();

	virtual void StartPlay() override;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Reverse")
	bool isReversed;
};



