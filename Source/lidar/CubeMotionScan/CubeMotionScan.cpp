// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeMotionScan.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "../mothinScan/MotionScan.h"

// Sets default values
ACubeMotionScan::ACubeMotionScan()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cube"));
	RootComponent = cube;

	EverythingIsDone = false;
}

// Called when the game starts or when spawned
void ACubeMotionScan::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ACubeMotionScan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(StartScanning)
		CaptureMngr();
	//CubeFaceSpawningMngr(0);
	
	//UE_LOG(LogTemp, Warning, TEXT("%d of %d"), capIdx, TA_domes.Num());
	//UE_LOG(LogTemp, Warning, TEXT("%d"), capIdx);
	
}


void ACubeMotionScan::CaptureMngr() {

	/*
	if (!FirstMC_initialized) {
		FirstMC_initialized = true;
		CapDataReset = false;
		CubeFaceSpawningMngr(capIdx);
		_motionCap->start_Capturing = true;
		
	}
	*/

	if (EverythingIsDone)
		return;


	if (capIdx >= 6) {
		if (!EverythingIsDone) {
			//UE_LOG(LogTemp, Warning, TEXT("alldone"));
			//for last dome
			AllScanDone();

			EverythingIsDone = true;
		}
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("gg"));
		if (!CapDataReset) {
			if (_motionCap->DataCaptured) {
				//UE_LOG(LogTemp, Warning, TEXT("dataCaptured"));
				CompileData();
				capIdx++;
				CapDataReset = true;
				
			}
		}
		else {
			//UE_LOG(LogTemp, Warning, TEXT("capdataReset"));
			if(_motionCap)
				_motionCap->Destroy();
			CubeFaceSpawningMngr(capIdx);
			_motionCap->start_Capturing = true;
			CapDataReset = false;
				
		}

		
	}
}

void ACubeMotionScan::CompileData() {
	UE_LOG(LogTemp, Warning, TEXT("comipilie satat"));
	_motionCap->MakeStrData();
	_motionCap->capture->TextureTarget = nullptr;

	for (int i = 0; i < _motionCap->Data.Num(); i++) {
		Main_Data.Add(_motionCap->Data[i]);
	}
}


void ACubeMotionScan::CubeFaceSpawningMngr(int idx) {
		
	if (idx == 0) {
		//face1
		FVector loc1 = RootComponent->GetRelativeLocation();
		loc1.X -= RootComponent->GetRelativeScale3D().X * (cubeLengthUnits / 2);
		loc1.Y -= RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits / 2);
		loc1.Z -= RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits / 2);
		FRotator rot1 = RootComponent->GetComponentRotation();
		FVector scale1 = RootComponent->GetRelativeScale3D();
		scale1.Y = 1;

		MC_Spawner(loc1, rot1, scale1);
	}
		
	if (idx == 1) {
		//face2
		FVector loc2 = RootComponent->GetRelativeLocation();
		loc2.X += RootComponent->GetRelativeScale3D().X * (cubeLengthUnits / 2);
		loc2.Y += RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits / 2);
		loc2.Z -= RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits / 2);
		FRotator rot2 = RootComponent->GetComponentRotation();
		rot2.Yaw += 180;
		FVector scale2 = RootComponent->GetRelativeScale3D();
		scale2.Y = 1;

		MC_Spawner(loc2, rot2, scale2);
	}
		
		
	if (idx == 2) {
		//face3
		FVector loc3 = RootComponent->GetRelativeLocation();
		loc3.X += RootComponent->GetRelativeScale3D().X * (cubeLengthUnits / 2);
		loc3.Y -= RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits / 2);
		loc3.Z -= RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits / 2);
		FRotator rot3 = RootComponent->GetComponentRotation();
		rot3.Yaw += 90;
		FVector scale3 = RootComponent->GetRelativeScale3D();
		scale3.X = scale3.Y;
		scale3.Y = 1;

		MC_Spawner(loc3, rot3, scale3);
	}

		
	if (idx == 3) {
		//face4
		FVector loc4 = RootComponent->GetRelativeLocation();
		loc4.X -= RootComponent->GetRelativeScale3D().X * (cubeLengthUnits / 2);
		loc4.Y += RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits / 2);
		loc4.Z -= RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits / 2);
		FRotator rot4 = RootComponent->GetComponentRotation();
		rot4.Yaw -= 90;
		FVector scale4 = RootComponent->GetRelativeScale3D();
		scale4.X = scale4.Y;
		scale4.Y = 1;


		MC_Spawner(loc4, rot4, scale4);
	}

		
	if (idx == 4) {
		//face5
		FVector loc5 = RootComponent->GetRelativeLocation();
		loc5.X -= RootComponent->GetRelativeScale3D().X * (cubeLengthUnits / 2);
		loc5.Y += RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits / 2);
		loc5.Z -= RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits / 2);
		FRotator rot5 = RootComponent->GetComponentRotation();
		rot5.Roll -= 90;
		FVector scale5 = RootComponent->GetRelativeScale3D();
		scale5.Z = scale5.Y;
		scale5.Y = 1;


		MC_Spawner(loc5, rot5, scale5);
	}


	if (idx == 5) {
		//face6
		FVector loc6 = RootComponent->GetRelativeLocation();
		loc6.X -= RootComponent->GetRelativeScale3D().X * (cubeLengthUnits / 2);
		loc6.Y -= RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits / 2);
		loc6.Z += RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits / 2);
		FRotator rot6 = RootComponent->GetComponentRotation();
		rot6.Roll += 90;
		FVector scale6 = RootComponent->GetRelativeScale3D();
		scale6.Z = scale6.Y;
		scale6.Y = 1;


		MC_Spawner(loc6, rot6, scale6);
	}
 

}

void ACubeMotionScan::MC_Spawner(FVector loc, FRotator rot, FVector scale) {
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	if (GetWorld()) {
		_motionCap = GetWorld()->SpawnActor<AMotionScan>(A_MC, loc, rot, spawnPara);
		_motionCap->SetActorScale3D(scale);

		_motionCap->capture->TextureTarget = RT_tex;
		_motionCap->NeedToCaptureColor = NeedToCaptureColor;
		_motionCap->ScanIterator = ScanIterator;
		_motionCap->TraceLen = TraceLen;
		_motionCap->planeDim = planeDim;
		_motionCap->drawDebugRay = drawDebugRay;
		_motionCap->drawDebugRay_Timer = drawDebugRay_Timer;
		_motionCap->Itr_planeTranverseAxisPos = Itr_planeTranverseAxisPos;
		_motionCap->Num_Of_LineTrace_At_A_Time = Num_Of_LineTrace_At_A_Time;


		if (capIdx == 0)
			_motionCap->Lmt_planeTranverseAxisPos = RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits);
		else if (capIdx == 1)
			_motionCap->Lmt_planeTranverseAxisPos = RootComponent->GetRelativeScale3D().Y * (cubeLengthUnits);
		else if (capIdx == 2)
			_motionCap->Lmt_planeTranverseAxisPos = RootComponent->GetRelativeScale3D().X * (cubeLengthUnits);
		else if (capIdx == 3)
			_motionCap->Lmt_planeTranverseAxisPos = RootComponent->GetRelativeScale3D().X * (cubeLengthUnits);
		else if (capIdx == 4)
			_motionCap->Lmt_planeTranverseAxisPos = RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits);
		else if (capIdx == 5)
			_motionCap->Lmt_planeTranverseAxisPos = RootComponent->GetRelativeScale3D().Z * (cubeLengthUnits);

		
	}
}

void ACubeMotionScan::AllScanDone() {
	if(CreateCustomPointCloud)
		writeToFile();
}

