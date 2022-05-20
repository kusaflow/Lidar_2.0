// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenVoxels.generated.h"

UCLASS()
class LIDAR_API AGenVoxels : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenVoxels();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		class UStaticMeshComponent* cube;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		TSubclassOf<class AActor> dots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float cap_Size = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "customVar")
		float unitLen = 100;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DrawVox();
	
	void fullFillup();

};
