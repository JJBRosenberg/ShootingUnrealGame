// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SecondShooterGameMode.generated.h"

UCLASS()
class ASecondShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//ASecondShooterGameMode();
	virtual void PawnKilled(APawn* PawnKilled);
};



