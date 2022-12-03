// Fill out your copyright notice in the Description page of Project Settings.
#include "MyAIController.h"
#include "SecondShooterCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AMyAIController::BeginPlay(){
    Super::BeginPlay();
    if(AIBehavior != nullptr){
        RunBehaviorTree(AIBehavior);
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        //GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }

}

void AMyAIController::Tick(float DeltaSeconds){
    Super::Tick(DeltaSeconds);
     APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

     if(LineOfSightTo(PlayerPawn)){

         GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
         GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
     } else {
         GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
     }
    
}

bool AMyAIController::IsDead() const{
    ASecondShooterCharacter* ControlledCharacter = Cast<ASecondShooterCharacter>(GetPawn());
    if(ControlledCharacter != nullptr){
        return ControlledCharacter->IsDead();
    }
    return true;
}