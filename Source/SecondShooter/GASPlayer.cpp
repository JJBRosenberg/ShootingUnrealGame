// Fill out your copyright notice in the Description page of Project Settings.


#include "GASPlayer.h"

// Sets default values
AGASPlayer::AGASPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGASPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGASPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGASPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

