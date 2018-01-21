#pragma once
#include "GlobalStructs.generated.h"

UENUM(BlueprintType)
enum class EGripState : uint8
{
	Open,
	CanGrab,
	Grab
};