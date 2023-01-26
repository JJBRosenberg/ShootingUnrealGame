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
	
	UFUNCTION(BlueprintImplementableEvent)
	void MyBPEvent();

	UFUNCTION(BlueprintCallable)
	bool Pay(int cost);

	UFUNCTION(BlueprintPure)
	int GetScore() const;

	UFUNCTION(BlueprintPure)
	int GetTime() const;

	UFUNCTION(BlueprintCallable)
	bool getDone();

	UPROPERTY(VisibleAnywhere)
	bool isDone = false;
	
	UFUNCTION(BlueprintCallable)
	void AddTime(float numb) ;

	UPROPERTY(VisibleAnywhere)
	int Score;
	UPROPERTY(VisibleAnywhere)
	float TimeCount;
	void EndGame(bool bIsPlayerWinner);
private:
	void LoadLevel();
};
