// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "TimerManager.h"
#include "SecondShooterGameMode.h"  


void AShooterPlayerController::BeginPlay() {
    Super::BeginPlay();
        HUDScreen = CreateWidget(this, HUDClass);
        if(HUDScreen != nullptr){
            HUDScreen->AddToViewport();
        } 
    
}
void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) {
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    HUDScreen->RemoveFromViewport();
    UE_LOG(LogTemp, Warning, TEXT("KILLEd"));
    if(bIsWinner){
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if(WinScreen != nullptr){
            WinScreen->AddToViewport();
        }  
    } else 
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if(LoseScreen != nullptr){
            LoseScreen->AddToViewport();
        }   
    }
   
   
    GetWorldTimerManager().SetTimer(RestartTimer, this, &AShooterPlayerController::MainMenu,RestartDelay);
}

void AShooterPlayerController::MainMenu(){
    ASecondShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<ASecondShooterGameMode>();
		if(GameMode != nullptr){
			GameMode->LoadLevel();
		}
    
}

