// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EntryTable.generated.h"


USTRUCT(BlueprintType)
struct FSchemaEntry : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:

    FSchemaEntry()
        : Area(0)
        , EntryCode(0)
    {}

    
    /** The 'Name' column is the same as the XP Level */

    /** XP to get to the given level from the previous level */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
        int32 Area;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
        int32 EntryCode;

};