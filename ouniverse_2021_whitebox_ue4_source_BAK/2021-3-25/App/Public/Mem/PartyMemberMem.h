// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartyMemberMem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPartyMemberMem
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int CompanionKey = -1;

};