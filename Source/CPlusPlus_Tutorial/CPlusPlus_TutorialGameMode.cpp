// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPlusPlus_TutorialGameMode.h"
#include "CPlusPlus_TutorialCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPlusPlus_TutorialGameMode::ACPlusPlus_TutorialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
