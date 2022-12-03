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

bool ASurvivalGameMode::Pay(int cost) {
    if(cost < Score){
        Score -= cost;
        return true;
    } else {
        return false;
    }
}
void ASurvivalGameMode::EndGame(bool bIsPlayerWinner){
    
}