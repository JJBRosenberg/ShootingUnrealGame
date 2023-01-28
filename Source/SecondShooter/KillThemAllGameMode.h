// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SecondShooterGameMode.h"
#include "GameFramework/Actor.h"
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

	UFUNCTION(BlueprintImplementableEvent)
	void MyBPEvent();

	UFUNCTION(BlueprintCallable)
	void AddTime(float numb) ;

	UFUNCTION(BlueprintPure)
	int GetTime() const;

	UFUNCTION(BlueprintImplementableEvent)
	void AddPoints();

	UPROPERTY(VisibleAnywhere)
	float TimeCount;

	UFUNCTION(BlueprintCallable)
	bool getDone();

	UPROPERTY(VisibleAnywhere)
	bool isDone = false;


	void EndGame(bool bIsPlayerWinner);
private:
	void LoadLevel();
};
