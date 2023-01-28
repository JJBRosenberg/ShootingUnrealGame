// Fill out your copyright notice in the Description page of Project Settings.
#include "KillThemAllGameMode.h"
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "MyAIController.h"
void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled){
    Super::PawnKilled(PawnKilled);
    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    //AddPoints();
    if(PlayerController != nullptr){
        EndGame(false);
    }
    for(AMyAIController* Controller : TActorRange< AMyAIController>(GetWorld())){
        if(!Controller->IsDead()){
            return;
        }
    }
    EndGame(true);
}
void AKillThemAllGameMode::AddTime(float numb) {
    TimeCount += numb;
}
int AKillThemAllGameMode::GetTime() const {
    return TimeCount;
}
bool AKillThemAllGameMode::getDone(){
    return isDone;
}
void AKillThemAllGameMode::EndGame(bool bIsPlayerWinner){
    isDone = true;
    for(AController* Controller : TActorRange<AController>(GetWorld())) {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
void AKillThemAllGameMode::LoadLevel(){
    
    MyBPEvent();
}