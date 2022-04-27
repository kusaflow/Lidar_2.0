// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCube_Mngr.generated.h"

UCLASS()
class LIDAR_API AMainCube_Mngr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainCube_Mngr();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		TArray<class ACubeMotionScan*> TA_domes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		class UTextureRenderTarget2D* RT_tex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		TArray<FString> Main_Data;



	int capIdx = 0;

	bool CapDataReset = true;


	bool EverythingIsDone = false;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AllDone();
	void MakeData();

	UFUNCTION(BlueprintImplementableEvent, Category = "customF")
		void writeToFile();

};
