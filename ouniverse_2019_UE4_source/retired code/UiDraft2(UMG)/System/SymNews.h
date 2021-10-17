//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymNews.generated.h"

class USystemUi;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_News : public UUiView
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_News* Create(UUiView* InParentView);

	void Init(UUiView* InParentView);

};