// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicGameMode.h"
#include "BasicGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

void ABasicGameMode::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	TArray<AActor*> array;
	//AcameraEffectActor = FindObject<ACameraEffectActor>(nullptr, TEXT("BP_CameraEffectActor"), false);
	const UObject* world = Cast<UObject>(GetWorld());

	settings = new SettingsManager(playerName, saveSlotSettings, userIndex);

}

bool ABasicGameMode::IsGamePaused() const
{
	return bGamePaused;
}

void ABasicGameMode::SetGamePaused(bool val)
{
	if (!bGamePaused && val)
	{
		if (pauseWidgetClass != nullptr)
		{
			pauseWidget = CreateWidget<UUserWidget>(GetGameInstance(), pauseWidgetClass);
		}
		if (pauseWidget != nullptr)
		{
			pauseWidget->AddToViewport(1);
		}
	}
	if (bGamePaused && !val)
	{
		if (pauseWidget != nullptr)
		{
			pauseWidget->RemoveFromViewport();
			pauseWidget = nullptr;
		}
	}
	
	bGamePaused = val;
	GetDefaultPlayerController()->SetPause(val);
}

// Called when the game starts or when spawned
void ABasicGameMode::BeginPlay()
{
	Super::BeginPlay();
	

}

ABasicCharacter * ABasicGameMode::GetDefaultCharacter() const
{
	return Cast<ABasicCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
}

ABasicPlayerController * ABasicGameMode::GetDefaultPlayerController() const
{
	return Cast<ABasicPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}



