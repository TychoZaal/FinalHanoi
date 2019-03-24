// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class TOWEROFHANOIUNREAL_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> ToSpawn;

	UPROPERTY()
	TArray< TSubclassOf<class AActor> > ArrayOfClasses;

	UFUNCTION(BlueprintCallable)
	void Spawn();

private:

	UPROPERTY(EditAnywhere)
	FVector spawnLocation1;
	
	UPROPERTY(EditAnywhere)
	FVector spawnLocation2;

	UPROPERTY(EditAnywhere)
	FVector	spawnLocation3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
