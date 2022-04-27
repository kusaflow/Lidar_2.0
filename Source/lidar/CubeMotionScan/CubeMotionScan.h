// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeMotionScan.generated.h"

UCLASS()
class LIDAR_API ACubeMotionScan : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeMotionScan();

	int capIdx = 0;

	bool CapDataReset = true;


	bool EverythingIsDone = false;
	bool StartScanning = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		class UStaticMeshComponent* cube;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
	TSubclassOf<class AMotionScan> A_MC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float cubeLengthUnits = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		TArray<FString> Main_Data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		class UTextureRenderTarget2D* RT_tex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		bool NeedToCaptureColor = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float ScanIterator = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float TraceLen = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		FVector planeDim = FVector(200, 0, 200);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		bool drawDebugRay = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float drawDebugRay_Timer = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float Itr_planeTranverseAxisPos = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		int Num_Of_LineTrace_At_A_Time = 20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		bool CreateCustomPointCloud = false;


	class AMotionScan* _motionCap;

	bool FirstMC_initialized = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CubeFaceSpawningMngr(int idx);
	void MC_Spawner(FVector loc, FRotator rot, FVector scale);

	void CaptureMngr();
	void CompileData();
	void AllScanDone();


	UFUNCTION(BlueprintImplementableEvent, Category = "customF")
		void writeToFile();

	////////////////////////////////////////
public:
	bool test = true;
	
};
