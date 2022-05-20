// Fill out your copyright notice in the Description page of Project Settings.


#include "GenVoxels.h"

// Sets default values
AGenVoxels::AGenVoxels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cube"));
	RootComponent = cube;

}

// Called when the game starts or when spawned
void AGenVoxels::BeginPlay()
{
	Super::BeginPlay();


	/// ////////////
	//DrawVox();
	fullFillup();

	
}

// Called every frame
void AGenVoxels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AGenVoxels::DrawVox() {
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	UWorld* world = GetWorld();
	
	//scale 
	FVector scale = RootComponent->GetComponentScale();
	FVector tmp = FVector(0);


	FVector p1 = RootComponent->GetComponentLocation();
	world->SpawnActor<AActor>(dots, p1, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p2 = RootComponent->GetForwardVector() * scale.X * unitLen;
	p2 += p1;
	p2 += RootComponent->GetRightVector() * scale.Y * unitLen;
	p2 += RootComponent->GetUpVector() * scale.Z * unitLen;
	world->SpawnActor<AActor>(dots, p2, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p3 = RootComponent->GetForwardVector() * scale.X * unitLen;
	p3 += p1;
	p3 += RootComponent->GetRightVector() * scale.Y * unitLen * -1;
	p3 += RootComponent->GetUpVector() * scale.Z * unitLen;
	world->SpawnActor<AActor>(dots, p3, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p4 = RootComponent->GetForwardVector() * scale.X * unitLen;
	p4 += p1;
	p4 += RootComponent->GetRightVector() * scale.Y * unitLen * -1;
	p4 += RootComponent->GetUpVector() * scale.Z * unitLen * -1;
	world->SpawnActor<AActor>(dots, p4, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p5 = RootComponent->GetForwardVector() * scale.X * unitLen;
	p5 += p1;
	p5 += RootComponent->GetRightVector() * scale.Y * unitLen;
	p5 += RootComponent->GetUpVector() * scale.Z * unitLen * -1;
	world->SpawnActor<AActor>(dots, p5, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	//==============================================
	///-----------------------------------
	FVector p6 = RootComponent->GetForwardVector() * scale.X * unitLen * -1;
	p6 += p1;
	p6 += RootComponent->GetRightVector() * scale.Y * unitLen;
	p6 += RootComponent->GetUpVector() * scale.Z * unitLen;
	world->SpawnActor<AActor>(dots, p6, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p7 = RootComponent->GetForwardVector() * scale.X * unitLen * -1;
	p7 += p1;
	p7 += RootComponent->GetRightVector() * scale.Y * unitLen * -1;
	p7 += RootComponent->GetUpVector() * scale.Z * unitLen;
	world->SpawnActor<AActor>(dots, p7, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p8 = RootComponent->GetForwardVector() * scale.X * unitLen * -1;
	p8 += p1;
	p8 += RootComponent->GetRightVector() * scale.Y * unitLen * -1;
	p8 += RootComponent->GetUpVector() * scale.Z * unitLen * -1;
	world->SpawnActor<AActor>(dots, p8, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));

	///-----------------------------------
	FVector p9 = RootComponent->GetForwardVector() * scale.X * unitLen * -1;
	p9 += p1;
	p9 += RootComponent->GetRightVector() * scale.Y * unitLen;
	p9 += RootComponent->GetUpVector() * scale.Z * unitLen * -1;
	world->SpawnActor<AActor>(dots, p9, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));



}  


void AGenVoxels :: fullFillup() {

	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	UWorld* world = GetWorld();

	//scale 
	FVector scale = RootComponent->GetComponentScale();
	FVector p1 = RootComponent->GetComponentLocation();


	for (float frnt = scale.X * unitLen * -1; frnt <= scale.X * unitLen; frnt += cap_Size * unitLen) {
		for (float rght = scale.Y * unitLen * -1; rght <= scale.Y * unitLen; rght += cap_Size * unitLen) {
			for (int up = scale.Z * unitLen * -1; up <= scale.Z * unitLen; up += cap_Size * unitLen) {
				FVector p9 = RootComponent->GetForwardVector() * frnt;
				p9 += p1;
				p9 += RootComponent->GetRightVector() * rght;
				p9 += (RootComponent->GetUpVector() * up);
				world->SpawnActor<AActor>(dots, p9, FRotator(0), spawnPara)->SetActorScale3D(FVector(cap_Size));
			}
		}
	}



}








