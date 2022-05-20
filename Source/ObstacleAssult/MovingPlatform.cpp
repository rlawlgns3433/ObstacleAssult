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

	//모든 코드는 Super::BeginPlay(); 다음에 작성해야 한다.


}

// 매 프레임 마다 실행
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector LocalVector = MyVector;

	LocalVector.Z += 100;

	// MyVector를 cube로 만들어 움직이는 cube로 만듦
	MyVector.Z = MyVector.Z + 1; // 매 프레임마다 cube가 Z방향으로 1씩 증가
	MyVector.Y = MyVector.Y + 1; // 매 프레임마다 cube가 Y방향으로 1씩 증가

	SetActorLocation(LocalVector); // 액터의 위치를 지정
}

