// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

//Playerª¬ŞÒïïËå×îªËª¤ªëªÈPlayerÛ°ú¾ªËTowerª¬üŞª¹ªë
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

	//TankªòÜÁğíª¹ªë
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	//?ŞÒéÄ«¿«¤«Ş?àâïÒ
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

		//Tankª¬ŞÒïïËå×îªÊª¤ªËìıªÃª¿ªé¡¢
		if (Distance <= FireRange)
		{
			return true;
		}
	}
	
	return false;
}