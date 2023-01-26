// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalGameMode.h"

void ASurvivalGameMode::PawnKilled(APawn* PawnKilled){
    UE_LOG(LogTemp, Warning, TEXT("Score inscread" ));
    Super::PawnKilled(PawnKilled);

    isDone = true;
    EndGame(true);

    /*APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    Score += 100;
    if(PlayerController != nullptr){
        EndGame(false);
    }
    for(AMyAIController* Controller : TActorRange< AMyAIController>(GetWorld())){
        if(!Controller->IsDead()){
            return;
        }
    }
    EndGame(true);*/
    
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
    
    
    for(AController* Controller : TActorRange<AController>(GetWorld())) {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}

void ASurvivalGameMode::LoadLevel(){
    
    MyBPEvent();
}