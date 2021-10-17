// Fill out your copyright notice in the Description page of Project Settings.


#include "Playthrough.h"
#include "Story.h"

APlaythrough::APlaythrough()
{
	PrimaryActorTick.bCanEverTick = false;
}

UStory* APlaythrough::GetActiveStory()
{
	return ActiveStory;
}

void APlaythrough::SetActiveStory(UStory* Story)
{
	ActiveStory = Story;
}

void APlaythrough::SetActiveStoryBP(UStory* Story, UStory*& StoryR)
{
	StoryR = Story;
	SetActiveStory(Story);
}