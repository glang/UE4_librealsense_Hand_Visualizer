// Fill out your copyright notice in the Description page of Project Settings.

#include "Hand_Visualizer.h"
#include "TestActor.h"
#include "Engine.h"
#include "librealsense/rs.hpp"
#include <vector>
#include <iostream>

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	std::cout << "begin play function is called" << std::endl;
	Super::BeginPlay();

	print("IT'S WORKING!");
		 
	rs::context ctx;
	if (ctx.get_device_count() == 0) throw std::runtime_error("No device detected. Is it plugged in?");

	// Enumerate all devices
	std::vector<rs::device *> devices;
	for (int i = 0; i<ctx.get_device_count(); ++i)
	{
		devices.push_back(ctx.get_device(i));
	}

	// Configure and start our devices
	for (auto dev : devices)
	{
		std::cout << "Starting " << dev->get_name() << "... ";
		dev->enable_stream(rs::stream::depth, rs::preset::best_quality);
		dev->enable_stream(rs::stream::color, rs::preset::best_quality);
		dev->start();
		std::cout << "done." << std::endl;
	}

}

// Called every frame
void ATestActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

