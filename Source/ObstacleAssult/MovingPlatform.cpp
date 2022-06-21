// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// ���� ����
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//��� �ڵ�� Super::BeginPlay(); ������ �ۼ��ؾ� �Ѵ�.
	UE_LOG(LogTemp, Display, TEXT("BeginPlay!"));
	StartLocation = GetActorLocation();
}

// �� ������ ���� ����
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// �̵� ������ �Ÿ� ���� ���� �������� ��
	if (ShouldPlatformReturn())
	{
		// MoveDirection : �÷����� ������ ���� �̵� ������ ���Ѵ�.
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		// StartLocation�� ����� ��ġ�� ������Ʈ �Ѵ�.
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		// ������ ���� ��ġ�� �����Ѵ�.
		SetActorLocation(StartLocation);
		// �÷����� �ӵ��� -�� ���� �ݴ��� �ӷ��� ���� �Ѵ�.
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		// ���� ��ġ �ޱ�
		FVector CurrentLocation = GetActorLocation();
		// �� ��ġ�� ���� �߰��ϱ�
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// �ش� ��ġ �����ϱ�
		SetActorLocation(CurrentLocation);
		
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{

	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	SetActorRotation(CurrentRotation);
}

//�ݴ�� �������� �ϴ����� ��ȯ
bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

// �󸶳� ���������� ��ȯ
float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}