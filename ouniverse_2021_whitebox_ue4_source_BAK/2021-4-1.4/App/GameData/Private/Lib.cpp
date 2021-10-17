// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Blue.h"

ULib::ULib()
{

}

void ULib::SetID(FString InID)
{
	ID = InID;
}

void ULib::Init()
{	
#if UE_BUILD_DEVELOPMENT 
	FBlueEnsureImplementation BEF = FBlueEnsureImplementation();
	BEF.Add("PreSSBP");
	BEF.Add("PostSSBP");
	BEF.Add("PostInitBP");
	BEF.Go(this, ID);
#endif

	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Init()");

	PreSSBP();

	TArray<FSoftObjectPath> ItemsToStream;
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();

	for (TSoftClassPtr<UObject> SoftClass : SoftClasses)
	{
		ItemsToStream.AddUnique(SoftClass.ToSoftObjectPath());
	}

	if (ItemsToStream.Num() == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "No story classes were registered in "+ID);
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "No SoftClasses were registered.");
	}
	else
	{
		Log.Write(AAUTH, LNORM, VNONE, 1, 0, "Loading SoftClass. Registered: " + FString::FromInt(ItemsToStream.Num()));
		Streamable.RequestAsyncLoad(ItemsToStream, FStreamableDelegate::CreateUObject(this, &ULib::PostSS));
	}
}

void ULib::PostInit()
{

}

void ULib::RegSCP(TSoftClassPtr<UObject> StoryClass)
{
	if (StoryClass.IsNull())
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A SoftClass was NULL! "+ID);
		Log.Write(AAUTH, LCRIT, VNONE, 1, 0, "A SoftClass was NULL!");
	}
	SoftClasses.Add(StoryClass);
}

void ULib::Complete()
{
	Log.Write(AAUTH, LNORM, VNONE, 1, 0, "InitComplete. Calling OnInitComplete Delegate.");
	bInit = true;
	OnInitComplete.Broadcast(this);
}