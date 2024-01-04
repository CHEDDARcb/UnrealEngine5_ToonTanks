// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

//Playerª¬ŞÒïïËå×î?ªËª¤ªëªÈPlayerÛ°ú¾ªËTowerª¬üŞ?ª¹ªë
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank != nullptr)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		
		//Tankª¬ŞÒïïËå×îªÊª¤ªËìıªÃª¿ªé¡¢
		if (Distance <= FireRange)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}
}

//TankªÎêÈöÇªòÜÁğíª¹ªë
void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}