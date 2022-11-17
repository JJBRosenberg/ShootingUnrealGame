// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SecondShooterGameMode.h"
#include "KillThemAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SECONDSHOOTER_API AKillThemAllGameMode : public ASecondShooterGameMode
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled) override;
	


private:
	void EndGame(bool bIsPlayerWinner);
};
