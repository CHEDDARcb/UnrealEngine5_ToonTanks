// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

//Player����������˪����Player۰����Tower���ު���
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	//Tank��������
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//?���ī�����?����
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();
	}
}

bool ATower::InFireRange()
{
	if (Tank != nullptr)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		//Tank����������ʪ������ê��顢
		if (Distance <= FireRange)
		{
			return true;
		}
	}
	
	return false;
}