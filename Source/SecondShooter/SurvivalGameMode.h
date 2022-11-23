// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "MyAIController.h"
#include "CoreMinimal.h"
#include "SecondShooterGameMode.h"
#include "SurvivalGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SECONDSHOOTER_API ASurvivalGameMode : public ASecondShooterGameMode
{
	GENERATED_BODY()
	

public:
	virtual void PawnKilled(APawn* PawnKilled) override;


	UFUNCTION(BlueprintPure)
	int GetScore() const;

	UPROPERTY(VisibleAnywhere)
	int Score;
private:
	void EndGame(bool bIsPlayerWinner);
};
