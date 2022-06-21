// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// 게임 시작
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//모든 코드는 Super::BeginPlay(); 다음에 작성해야 한다.
	UE_LOG(LogTemp, Display, TEXT("BeginPlay!"));
	StartLocation = GetActorLocation();
}

// 매 프레임 마다 실행
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// 이동 가능한 거리 보다 많이 움직였을 때
	if (ShouldPlatformReturn())
	{
		// MoveDirection : 플랫폼의 법선을 구해 이동 방향을 구한다.
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		// StartLocation의 방향과 위치를 업데이트 한다.
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		// 액터의 시작 위치를 설정한다.
		SetActorLocation(StartLocation);
		// 플랫폼의 속도에 -를 곱해 반대의 속력을 갖게 한다.
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		// 현재 위치 받기
		FVector CurrentLocation = GetActorLocation();
		// 그 위치에 벡터 추가하기
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// 해당 위치 설정하기
		SetActorLocation(CurrentLocation);
		
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{

	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);
}

//반대로 움직여야 하는지를 반환
bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

// 얼마나 움직였는지 반환
float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}