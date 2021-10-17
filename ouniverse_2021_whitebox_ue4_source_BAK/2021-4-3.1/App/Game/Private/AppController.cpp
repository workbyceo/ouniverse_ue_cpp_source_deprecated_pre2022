// Fill out your copyright notice in the Description page of Project Settings.


#include "AppController.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "AppMode.h"
#include "Cam.h"
#include "Input.h"
#include "Keynet.h"
#include "InterfaceInput.h"
#include "Kismet/GameplayStatics.h"
#include "MenuMain.h"
#include "Framework/Commands/InputChord.h"



#include "WorldPro.h"


#include "LoadScreenUi.h"

#include "SoftServe.h"


AAppController::AAppController()
{
	bReplicates = true;
	bAutoManageActiveCameraTarget = false;

	UserName = "Default";
	UserSymbol = 0;

	//WorldRemote = CreateDefaultSubobject(TEXT("WorldRemote"));

}

AAppController* AAppController::GetAppController(const UObject* WorldContextObject)
{
	return Cast<AAppController>(UGameplayStatics::GetPlayerController(WorldContextObject->GetWorld(), 0));
}

void AAppController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCameraManager->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AppControllerIndex = GetInputIndex();

	SoftServe = NewObject<USoftServe>(this, USoftServe::StaticClass());
	SoftServe->Add(WorldProClass);
	SoftServe->Add(LoadScreenUiClass);

	if (SoftServe->HasNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "ServeServe has Null in AppController");
		return;
	}

	SoftServe->OnComplete.AddDynamic(this, &AAppController::BeginPlay_SS);
	SoftServe->Stream();
}

void AAppController::BeginPlay_SS(USoftServe* SS)
{
	WorldPro = NewObject<UWorldPro>(this, WorldProClass.Get(), TEXT("WorldPro"));
	WorldPro->RegisterComponent();

	if (IsLocalPlayerController())
	{
		LoadScreenUi = CreateWidget<ULoadScreenUi>(this, LoadScreenUiClass.Get());
	}

	AAppMode* AppMode = Cast<AAppMode>(GetWorld()->GetAuthGameMode());
	if (IsValid(AppMode))
	{
		AppMode->ReceivePlayer(this);
	}

	SoftServe = NULL;
}

void AAppController::SetupInputComponent()
{
	Super::SetupInputComponent();

	BTs.Init(NULL, EInputBT::EInputBT_MAX);
	
	BTs.Add(UInputButton::Create(this, &EKeys::I, EInputBT::EInputBT_I));

	BTs[EInputBT::EInputBT_Gamepad_LeftTrigger] = UInputButton::Create(this, &EKeys::Gamepad_LeftTrigger, EInputBT::EInputBT_Gamepad_LeftTrigger);
	BTs[EInputBT::EInputBT_Gamepad_RightTrigger] = UInputButton::Create(this, &EKeys::Gamepad_RightTrigger, EInputBT::EInputBT_Gamepad_RightTrigger);

	BTs[EInputBT::EInputBT_Gamepad_FaceButton_Bottom] = UInputButton::Create(this, &EKeys::Gamepad_FaceButton_Bottom, EInputBT::EInputBT_Gamepad_FaceButton_Bottom);
	BTs[EInputBT::EInputBT_Gamepad_FaceButton_Right] = UInputButton::Create(this, &EKeys::Gamepad_FaceButton_Right, EInputBT::EInputBT_Gamepad_FaceButton_Right);



	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, EKeys::Gamepad_FaceButton_Bottom.ToString());

	TEnumAsByte<UInputButton> Byte = TEnumAsByte<UInputButton>(0);

	DefaultKeynet(EKeynets::EKeynets_Menu);
	DefaultKeynet(EKeynets::EKeynets_World);
}

void AAppController::DefaultKeynet(TEnumAsByte<EKeynets> Keynet)
{
	switch (Keynet) {
	case EKeynets::EKeynets_Menu:
			KeynetMenu = UKeynet::Create();
			KeynetMenu->AddKeymap(FKeymap(EKeynetMenu::EKeynetMenu_Accept, BTs[EInputBT::EInputBT_Gamepad_FaceButton_Bottom]));
			KeynetMenu->AddKeymap(FKeymap(EKeynetMenu::EKeynetMenu_Cancel, BTs[EInputBT::EInputBT_Gamepad_FaceButton_Right]));
			KeynetMenu->AddKeymap(FKeymap(EKeynetMenu::EKeynetMenu_TabLeft, BTs[EInputBT::EInputBT_Gamepad_LeftTrigger]));
			KeynetMenu->AddKeymap(FKeymap(EKeynetMenu::EKeynetMenu_TabRight, BTs[EInputBT::EInputBT_Gamepad_RightTrigger]));
			KeynetMenu->Rebuild();
		break;
	case EKeynets::EKeynets_World:
			KeynetWorld = UKeynet::Create();
			KeynetWorld->AddKeymap(FKeymap(EKeynetWorld::EKeynetWorld_Inventory, BTs[EInputBT::EInputBT_I]));
			KeynetWorld->Rebuild();
		break;
	}
}

void AAppController::SetRemoteMode(TEnumAsByte<ERemoteModes> InRemoteMode)
{
	switch (InRemoteMode) {
	case ERemoteModes::ERemoteModesNone:
		//ActiveRemote = NULL;
		break;
	case ERemoteModes::ERemoteModesWorld:
		//ActiveRemote = WorldRemote;
		//WorldRemote->Start();
		break;
	}
}

void AAppController::SendInputButtonEvent(UInputButton* InputButton)
{

	UInputButtonEvent* NewInputButtonEvent = NewObject<UInputButtonEvent>();
	NewInputButtonEvent->Fill(InputButton);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "KeyHappened");

	//if (IsValid(ActivePro))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "KeySent");
	//	WorldPro->BT(NewInputButtonEvent);
	//}
	
}

void AAppController::ConvertToKeynetBP(TEnumAsByte<EKeynets> Keynet, uint8 InputCode, uint8& ConvertedInputCode, ESuccessExecs& Execs)
{
	Execs = ESuccessExecs::Fail;
	ConvertedInputCode = 0;
	UKeynet* QueryKeynet = NULL;	

	switch (Keynet) {
	case EKeynets::EKeynets_Menu:
		QueryKeynet = KeynetMenu;
		break;
	case EKeynets::EKeynets_World:
		QueryKeynet = KeynetWorld;
		break;
	}

	if(QueryKeynet!=NULL&& QueryKeynet->TryBind(ConvertedInputCode, InputCode))
	{
		Execs = ESuccessExecs::Success;
	}
}

TEnumAsByte<EKeynetWorld> AAppController::KeynetConvertWorld(uint8 Byte)
{
	return EKeynetWorld::EKeynetWorld_Inventory;
}


bool AAppController::OpenMainMenu(FMenuMainInitializer Initializer)
{
	MenuMain = AMenuMainRootWin::OpenMenu(Initializer,MenuMainClass,this);
	return true;
}

bool AAppController::OpenConsole()
{
	return true;
}

bool AAppController::PrintScreen()
{
	return true;
}















void AAppController::StartLoadScreen_Implementation()
{
	if (LoadScreenUi)
	{
		LoadScreenUi->AddToViewport(9999);
	}
}

/** WithValidation
bool AAppController::StartLoadScreen_Validate()
{
	return true;
}
*/

void AAppController::EndLoadScreen()
{

}
