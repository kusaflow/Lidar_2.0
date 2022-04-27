// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCube_Mngr.h"
#include "CubeMotionScan.h"

// Sets default values
AMainCube_Mngr::AMainCube_Mngr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCube_Mngr::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCube_Mngr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TA_domes.Num() == 0)
		return;

	if (!EverythingIsDone) {
		if (capIdx >= TA_domes.Num()) {
			AllDone();
		}
		else
		{
			if (!CapDataReset) {
				if (TA_domes[capIdx]->EverythingIsDone) {
					CapDataReset = true;
					TA_domes[capIdx]->RT_tex = nullptr;
					capIdx++;
				}
			}
			else {
				if (CapDataReset) {
					TA_domes[capIdx]->StartScanning = true;
					TA_domes[capIdx]->RT_tex = RT_tex;
					CapDataReset = false;
				}
			}
		}
	}



}


void AMainCube_Mngr::AllDone() {
	MakeData();
	writeToFile();
	EverythingIsDone = true;
}

void AMainCube_Mngr::MakeData() {
	for (int i = 0; i < TA_domes.Num(); i++) {
		for (int j = 0; j < TA_domes[i]->Main_Data.Num(); j++) {
			Main_Data.Add(TA_domes[i]->Main_Data[j]);
		}
	}
}