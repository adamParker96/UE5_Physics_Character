// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APhysicsCharacter::APhysicsCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Skeletal Mesh components
	PhysicsMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PhysicsMeshComp"));
	TargetMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TargetMeshComp"));

	// Load Skeletal Mesh asset at runtime
	USkeletalMesh* DynamicMesh = LoadObject<USkeletalMesh>(nullptr, TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
	if (DynamicMesh)
	{
		PhysicsMeshComp->SetSkeletalMesh(DynamicMesh);
		TargetMeshComp->SetSkeletalMesh(DynamicMesh);
	}

	//  Enable Physics & Collision
	PhysicsMeshComp->SetSimulatePhysics(true);
	PhysicsMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//  Set angular damping
	PhysicsMeshComp->SetAngularDamping(10);

	//  Set Animation Blueprint for TargetMeshComp
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimBPClass(TEXT("/Game/Characters/Mannequins/Animations/ABP_Physics_Character.ABP_Physics_Character_C"));
	if (AnimBPClass.Succeeded())
	{
		TargetMeshComp->SetAnimInstanceClass(AnimBPClass.Class);
	}
}

// Called when the game starts or when spawned
void APhysicsCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APhysicsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//  Do pre-torque calculations
	
	//  Set Look At Point
	TArray<AActor*> FoundActors; 
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("LookAtMe"), FoundActors); 
	FVector LookAtPoint = FoundActors[0]->GetActorLocation(); //  Should only have one actor w/ "LookAtMe" tag for testing
	
	//  Check is Grounded
	//  Check is Upright

	//  Do Balance Logic :
	//	Pelvis
	//  Upper Body
	//  Arm Logic
	//  Leg Logic
}

// Called to bind functionality to input
void APhysicsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

