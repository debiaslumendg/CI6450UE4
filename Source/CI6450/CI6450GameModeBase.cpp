// Fill out your copyright notice in the Description page of Project Settings.


#include "CI6450GameModeBase.h"
#include "WBCPlayerController.h"

ACI6450GameModeBase::ACI6450GameModeBase()
{
    PlayerControllerClass = AWBCPlayerController::StaticClass();
}