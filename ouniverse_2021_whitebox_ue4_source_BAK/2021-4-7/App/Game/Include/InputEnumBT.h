// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputEnumBT.generated.h"


UENUM(BlueprintType)
enum InputEnumBT
{
	InputEnumBT_BackSpace  UMETA(DisplayName = "BackSpace"),
	InputEnumBT_Tab		UMETA(DisplayName = "Tab"),
	InputEnumBT_Enter		UMETA(DisplayName = "Enter"),
	InputEnumBT_Pause		UMETA(DisplayName = "Pause"),

	InputEnumBT_CapsLock  UMETA(DisplayName = "CapsLock"),
	InputEnumBT_Escape  UMETA(DisplayName = "Escape"),
	InputEnumBT_SpaceBar  UMETA(DisplayName = "SpaceBar"),
	InputEnumBT_PageUp  UMETA(DisplayName = "PageUp"),
	InputEnumBT_PageDown  UMETA(DisplayName = "PageDown"),
	InputEnumBT_End  UMETA(DisplayName = "End"),
	InputEnumBT_Home  UMETA(DisplayName = "Home"),

	InputEnumBT_Up  UMETA(DisplayName = "Up"),
	InputEnumBT_Down  UMETA(DisplayName = "Down"),
	InputEnumBT_Left  UMETA(DisplayName = "Left"),
	InputEnumBT_Right  UMETA(DisplayName = "Right"),

	InputEnumBT_Insert  UMETA(DisplayName = "Insert"),
	InputEnumBT_Delete  UMETA(DisplayName = "Delete"),

	InputEnumBT_Zero  UMETA(DisplayName = "Zero"),
	InputEnumBT_One  UMETA(DisplayName = "One"),
	InputEnumBT_Two  UMETA(DisplayName = "Two"),
	InputEnumBT_Three  UMETA(DisplayName = "Three"),
	InputEnumBT_Four  UMETA(DisplayName = "Four"),
	InputEnumBT_Five  UMETA(DisplayName = "Five"),
	InputEnumBT_Six  UMETA(DisplayName = "Six"),
	InputEnumBT_Seven  UMETA(DisplayName = "Seven"),
	InputEnumBT_Eight  UMETA(DisplayName = "Eight"),
	InputEnumBT_Nine  UMETA(DisplayName = "Nine"),

	InputEnumBT_A  UMETA(DisplayName = "A"),
	InputEnumBT_B  UMETA(DisplayName = "B"),
	InputEnumBT_C  UMETA(DisplayName = "C"),
	InputEnumBT_D  UMETA(DisplayName = "D"),
	InputEnumBT_E  UMETA(DisplayName = "E"),
	InputEnumBT_F  UMETA(DisplayName = "F"),
	InputEnumBT_G  UMETA(DisplayName = "G"),
	InputEnumBT_H  UMETA(DisplayName = "H"),
	InputEnumBT_I  UMETA(DisplayName = "I"),
	InputEnumBT_J  UMETA(DisplayName = "J"),
	InputEnumBT_K  UMETA(DisplayName = "K"),
	InputEnumBT_L  UMETA(DisplayName = "L"),
	InputEnumBT_M  UMETA(DisplayName = "M"),
	InputEnumBT_N  UMETA(DisplayName = "N"),
	InputEnumBT_O  UMETA(DisplayName = "O"),
	InputEnumBT_P  UMETA(DisplayName = "P"),
	InputEnumBT_Q  UMETA(DisplayName = "Q"),
	InputEnumBT_R	UMETA(DisplayName = "R"),
	InputEnumBT_S  UMETA(DisplayName = "S"),
	InputEnumBT_T  UMETA(DisplayName = "T"),
	InputEnumBT_U	UMETA(DisplayName = "U"),
	InputEnumBT_V  UMETA(DisplayName = "V"),
	InputEnumBT_W  UMETA(DisplayName = "W"),
	InputEnumBT_X  UMETA(DisplayName = "X"),
	InputEnumBT_Y  UMETA(DisplayName = "Y"),
	InputEnumBT_Z  UMETA(DisplayName = "Z"),

	InputEnumBT_NumPadZero  UMETA(DisplayName = "NumPadZero"),
	InputEnumBT_NumPadOne  UMETA(DisplayName = "NumPadOne"),
	InputEnumBT_NumPadTwo  UMETA(DisplayName = "NumPadTwo"),
	InputEnumBT_NumPadThree  UMETA(DisplayName = "NumPadThree"),
	InputEnumBT_NumPadFour  UMETA(DisplayName = "NumPadFour"),
	InputEnumBT_NumPadFive  UMETA(DisplayName = "NumPadFive"),
	InputEnumBT_NumPadSix  UMETA(DisplayName = "NumPadSix"),
	InputEnumBT_NumPadSeven  UMETA(DisplayName = "NumPadSeven"),
	InputEnumBT_NumPadEight  UMETA(DisplayName = "NumPadEight"),
	InputEnumBT_NumPadNine  UMETA(DisplayName = "NumPadNine"),

	InputEnumBT_Multiply  UMETA(DisplayName = "Multiply"),
	InputEnumBT_Add  UMETA(DisplayName = "Add"),
	InputEnumBT_Subtract  UMETA(DisplayName = "Subtract"),
	InputEnumBT_Decimal  UMETA(DisplayName = "Decimal"),
	InputEnumBT_Divide  UMETA(DisplayName = "Divide"),

	InputEnumBT_F1  UMETA(DisplayName = "F1"),
	InputEnumBT_F2  UMETA(DisplayName = "F2"),
	InputEnumBT_F3  UMETA(DisplayName = "F3"),
	InputEnumBT_F4  UMETA(DisplayName = "F4"),
	InputEnumBT_F5  UMETA(DisplayName = "F5"),
	InputEnumBT_F6  UMETA(DisplayName = "F6"),
	InputEnumBT_F7  UMETA(DisplayName = "F7"),
	InputEnumBT_F8  UMETA(DisplayName = "F8"),
	InputEnumBT_F9  UMETA(DisplayName = "F9"),
	InputEnumBT_F10  UMETA(DisplayName = "F10"),
	InputEnumBT_F11  UMETA(DisplayName = "F11"),
	InputEnumBT_F12  UMETA(DisplayName = "F12"),

	InputEnumBT_NumLock  UMETA(DisplayName = "NumLock"),

	InputEnumBT_ScrollLock  UMETA(DisplayName = "ScrollLock"),

	InputEnumBT_LeftShift  UMETA(DisplayName = "LeftShift"),
	InputEnumBT_RightShift  UMETA(DisplayName = "RightShift"),
	InputEnumBT_LeftControl  UMETA(DisplayName = "LeftControl"),
	InputEnumBT_RightControl  UMETA(DisplayName = "RightControl"),
	InputEnumBT_LeftAlt  UMETA(DisplayName = "LeftAlt"),
	InputEnumBT_RightAlt  UMETA(DisplayName = "RightAlt"),
	InputEnumBT_LeftCommand  UMETA(DisplayName = "LeftCommand"),
	InputEnumBT_RightCommand  UMETA(DisplayName = "RightCommand"),

	InputEnumBT_Semicolon  UMETA(DisplayName = "Semicolon"),
	InputEnumBT_Equals  UMETA(DisplayName = "Equals"),
	InputEnumBT_Comma  UMETA(DisplayName = "Comma"),
	InputEnumBT_Underscore  UMETA(DisplayName = "Underscore"),
	InputEnumBT_Hyphen  UMETA(DisplayName = "Hyphen"),
	InputEnumBT_Period  UMETA(DisplayName = "Period"),
	InputEnumBT_Slash  UMETA(DisplayName = "Slash"),
	InputEnumBT_Tilde  UMETA(DisplayName = "Tilde"),
	InputEnumBT_LeftBracket  UMETA(DisplayName = "LeftBracket"),
	InputEnumBT_Backslash  UMETA(DisplayName = "Backslash"),
	InputEnumBT_RightBracket  UMETA(DisplayName = "RightBracket"),
	InputEnumBT_Apostrophe  UMETA(DisplayName = "Apostrophe"),

	InputEnumBT_LeftMouseButton  UMETA(DisplayName = "LeftMouseButton"),
	InputEnumBT_RightMouseButton  UMETA(DisplayName = "RightMouseButton"),
	InputEnumBT_MiddleMouseButton  UMETA(DisplayName = "MiddleMouseButton"),
	InputEnumBT_ThumbMouseButton  UMETA(DisplayName = "ThumbMouseButton"),
	InputEnumBT_ThumbMouseButton2  UMETA(DisplayName = "ThumbMouseButton2"),

	InputEnumBT_Gamepad_FaceButton_Bottom  UMETA(DisplayName = "Gamepad_FaceButton_Bottom"),
	InputEnumBT_Gamepad_FaceButton_Right  UMETA(DisplayName = "Gamepad_FaceButton_Right"),
	InputEnumBT_Gamepad_FaceButton_Left  UMETA(DisplayName = "Gamepad_FaceButton_Left"),
	InputEnumBT_Gamepad_FaceButton_Top  UMETA(DisplayName = "Gamepad_FaceButton_Top"),
	InputEnumBT_Gamepad_Special_Left UMETA(DisplayName = "Gamepad_Special_Left"),
	InputEnumBT_Gamepad_Special_Right UMETA(DisplayName = "Gamepad_Special_Right"),

	InputEnumBT_Gamepad_LeftShoulder UMETA(DisplayName = "Gamepad_LeftShoulder"),
	InputEnumBT_Gamepad_RightShoulder UMETA(DisplayName = "Gamepad_RightShoulder"),
	InputEnumBT_Gamepad_LeftTrigger UMETA(DisplayName = "Gamepad_LeftTrigger"),
	InputEnumBT_Gamepad_RightTrigger UMETA(DisplayName = "Gamepad_RightTrigger"),
	InputEnumBT_Gamepad_LeftThumbstick UMETA(DisplayName = "Gamepad_LeftThumbstick"),
	InputEnumBT_Gamepad_RightThumbstick UMETA(DisplayName = "Gamepad_RightThumbstick"),
	InputEnumBT_Gamepad_DPad_Up UMETA(DisplayName = "Gamepad_DPad_Up"),
	InputEnumBT_Gamepad_DPad_Down UMETA(DisplayName = "Gamepad_DPad_Down"),
	InputEnumBT_Gamepad_DPad_Left UMETA(DisplayName = "Gamepad_DPad_Left"),
	InputEnumBT_Gamepad_DPad_Right UMETA(DisplayName = "Gamepad_DPad_Right"),
	InputEnumBT_Gamepad_LeftStick_Up UMETA(DisplayName = "Gamepad_LeftStick_Up"),
	InputEnumBT_Gamepad_LeftStick_Down UMETA(DisplayName = "Gamepad_LeftStick_Down"),
	InputEnumBT_Gamepad_LeftStick_Left UMETA(DisplayName = "Gamepad_LeftStick_Left"),
	InputEnumBT_Gamepad_LeftStick_Right UMETA(DisplayName = "Gamepad_LeftStick_Right"),
	InputEnumBT_Gamepad_RightStick_Up UMETA(DisplayName = "Gamepad_RightStick_Up"),
	InputEnumBT_Gamepad_RightStick_Down UMETA(DisplayName = "Gamepad_RightStick_Down"),
	InputEnumBT_Gamepad_RightStick_Left UMETA(DisplayName = "Gamepad_RightStick_Left"),
	InputEnumBT_Gamepad_RightStick_Right UMETA(DisplayName = "Gamepad_RightStick_Right"),
	InputEnumBT_MAX UMETA(DisplayName = "MAX"),
};