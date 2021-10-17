// Fill out your copyright notice in the Description page of Project Settings.


#include "SpectatorRemote.h"
#include "Log.h"
#include "AppController.h"
#include "SpectatorUi.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

USpectatorRemote::USpectatorRemote() : URemote(){}

void USpectatorRemote::Init_Implementation(AAppController* AP, UPartyPro* InPartyPro)
{
	URemote::Init(AP);
	PartyPro = InPartyPro;
}

void USpectatorRemote::BeginPlay()
{
	Super::BeginPlay();
}

void USpectatorRemote::Engage_SERVER()
{
	bEngaged = true;
	Engage_CLIENT();
}

void USpectatorRemote::Engage_CLIENT_Implementation()
{
	if (AppPlayer->IsLocalPlayerController())
	{
		FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
		Streamable.RequestAsyncLoad(AppPlayer->SpectatorUiClass.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &USpectatorRemote::Ui_AsyncLoad));
	}

	LOG.S("FUCK").N(this).W("SPECATOR REMOTE");
}

void USpectatorRemote::Ui_AsyncLoad()
{
	Ui = CreateWidget<USpectatorUi>(AppPlayer, AppPlayer->SpectatorUiClass.Get());
	Ui->AddToPlayerScreen(9999);
}