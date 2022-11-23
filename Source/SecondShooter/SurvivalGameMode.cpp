// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalGameMode.h"

void ASurvivalGameMode::PawnKilled(APawn* PawnKilled){
    UE_LOG(LogTemp, Warning, TEXT("Score inscread" ));
    Super::PawnKilled(PawnKilled);
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    Score += 100;
}

int ASurvivalGameMode::GetScore() const {
    return Score;
}
void ASurvivalGameMode::EndGame(bool bIsPlayerWinner){
    
}