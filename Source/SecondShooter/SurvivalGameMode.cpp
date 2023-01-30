// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalGameMode.h"

void ASurvivalGameMode::PawnKilled(APawn* PawnKilled){
    Super::PawnKilled(PawnKilled);
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    
    
    if(PlayerController != nullptr){
        EndGame(false);
    }
    for(AMyAIController* Controller : TActorRange< AMyAIController>(GetWorld())){
        if(!Controller->IsDead()){
            Score += 100;
            return;
        }
    }
    EndGame(true);
    
}

int ASurvivalGameMode::GetScore() const {
    return Score;
}
void ASurvivalGameMode::AddTime(float numb) {
    TimeCount += numb;
}
int ASurvivalGameMode::GetTime() const {
    return TimeCount;
}

bool ASurvivalGameMode::getDone(){
    return isDone;
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
    
    isDone = true;
    for(AController* Controller : TActorRange<AController>(GetWorld())) {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}

void ASurvivalGameMode::LoadLevel(){
    
    MyBPEvent();
}