// Fill out your copyright notice in the Description page of Project Settings.

#include "Block.h"
#include <Classes/Components/StaticMeshComponent.h>
#include "Engine/World.h"
#include <chrono>
#include <thread>
#include "Gameframework/Actor.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

// Sets default values
ABlock::ABlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
}

void ABlock::Spawn()
{
	if (ToSpawn)
	{
		UWorld * world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			FRotator rotator;

			FVector spawnLocation = spawnLocation1;

			world->SpawnActor<AActor>(ToSpawn, spawnLocation1, rotator, spawnParams);
			sleep_for(1s);
		}
	}
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();	
	for (size_t i = 0; i < 5; i++)
	{
		Spawn();
	}
}

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

