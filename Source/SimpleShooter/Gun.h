// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "FX")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, Category = "FX")
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere, Category = "FX")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, Category = "FX")
	USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float MaxRange = 1000;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float Damage = 10;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
