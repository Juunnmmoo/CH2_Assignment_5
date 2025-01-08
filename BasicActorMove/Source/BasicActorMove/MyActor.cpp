// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <cmath>



// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int step()
{
    int RandomNumber = FMath::RandRange(0, 1);

    return RandomNumber;
}

void Move(int* _x, int* _y)
{
    int speedX = step();
    int speedY = step();

    *_x += speedX;
    *_y += speedY;

    UE_LOG(LogTemp, Warning, TEXT("Movement speed ( X : %d, Y : %d )"), speedX, speedY);
}
    
float Distance(int _firstX, int _firstY, int _secondX, int _secondY)
{
    return sqrt(pow(_secondX - _firstX, 2) + pow(_secondY - _firstY, 2));
}

int CreateEvent()
{
    int RandomNumber = FMath::RandRange(0, 1);

    return RandomNumber;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();


    int posX = 0;
    int posY = 0;
    int temp_X = posX;
    int temp_Y = posY;
    int eventCnt = 0;

    UE_LOG(LogTemp, Display, TEXT("Start Location : ( %d, %d )"), posX, posY);

    for (size_t i = 0; i < 10; i++)
    {
        Move(&posX, &posY);
        UE_LOG(LogTemp, Display, TEXT("Current position : ( %d, %d )"), posX, posY);
        
        if (CreateEvent() == 1)
        {
            float distance = Distance(temp_X, temp_Y, posX, posY);
            UE_LOG(LogTemp, Error, TEXT("Event triggered!!  Distance traveled before the event is triggered  : %.2f"), distance);
            temp_X = posX;
            temp_Y = posY;
            eventCnt++;
        }
    }
    float distance = Distance(0, 0, posX, posY);
    UE_LOG(LogTemp, Display, TEXT("Event triggered Count : %d  Total distance  : %.2f"), eventCnt, distance);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


