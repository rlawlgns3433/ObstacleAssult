// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//��� �ڵ�� Super::BeginPlay(); ������ �ۼ��ؾ� �Ѵ�.


}

// �� ������ ���� ����
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector LocalVector = MyVector;

	LocalVector.Z += 100;

	// MyVector�� cube�� ����� �����̴� cube�� ����
	MyVector.Z = MyVector.Z + 1; // �� �����Ӹ��� cube�� Z�������� 1�� ����
	MyVector.Y = MyVector.Y + 1; // �� �����Ӹ��� cube�� Y�������� 1�� ����

	SetActorLocation(LocalVector); // ������ ��ġ�� ����
}

