// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InterfaceMount.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterfaceMount : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ONE_API IInterfaceMount
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//UFUNCTION(BlueprintCallable, Category = "MyCategory")
	//virtual bool ReactToHighNoon();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ControlInterface")
	void Mount();
	virtual void Mount_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ControlInterface")
	void Dismount();
	virtual void Dismount_Implementation();

};