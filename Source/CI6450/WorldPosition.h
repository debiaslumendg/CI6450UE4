// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldPosition.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CI6450_API UWorldPosition : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWorldPosition();

protected:

	FVector velocity;
	FVector rotation;
	AActor* _target;


	// Called when the game starts
	virtual void BeginPlay() override;
	FVector GetSteering(FVector target);
	void Update(float deltaTime, FVector linear, FVector angular);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
