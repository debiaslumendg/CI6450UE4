// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"
#include "GameFramework/WorldSettings.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	velocity = FVector(0, 0, 0);
	rotation = FVector(0, 0, 0);

	for (AActor* actor : GetWorld()->GetCurrentLevel()->Actors) {
		if (actor != NULL && actor->GetName().Equals(TEXT("Sphere_5"), ESearchCase::CaseSensitive)) {
			//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, actor->GetName())
			_target = actor;
		};
	}
	
	// ...
	
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector steering = GetSteering(_target->GetActorLocation());

	Update(DeltaTime, steering, steering);

	// ...
}

void UWorldPosition::Update(float DeltaTime, FVector linear, FVector angular) {

	AActor* actor = GetOwner();

	actor->SetActorLocation(actor->GetActorLocation() + velocity * DeltaTime);
	//actor->SetActorRotation(actor->GetActorRotation() + rotation.Rotation() * deltaTime);
	
	velocity = linear;
	//GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Blue, velocity.ToString());
	//rotation += angular * deltaTime;


}

FVector UWorldPosition::GetSteering(FVector target) {
	
	FVector _velocity = target - GetOwner()->GetActorLocation();
	_velocity.Normalize();
	_velocity *= 100;
	return _velocity;

}
