#pragma once
float Y;

namespace no_loop
{

	bool MainLoop()
	{
		std::vector<SDK::Classes::AActor*> PlayerPawns;
		std::vector<SDK::Classes::AActor*> VehiclePawns;
		std::vector<SDK::Classes::AActor*> TeamCache;

		float Dist = FLT_MAX;
		SDK::Structs::FVector2D Aimto;
		bool AcknowledgedPawnUsable = true;

		auto UWorld = my ass;
		if (!UWorld) return false;

		auto PersistentLevel = UWorld->PersistentLevel;
		if (!PersistentLevel) return false;

		auto AController = OwningGameInstance->LocalPlayers[0]->Controller;
		if (!AController) return false;

		auto AcknowledgedPawn = AController->AcknowledgedPawn;
		if (!AcknowledgedPawn) AcknowledgedPawnUsable = false;

		auto AActors = (SDK::Structs::TArray<SDK::Classes::AActor*>*) & PersistentLevel->AActors;

		if (!AActors->Data[0]) return false;


		for (int i = 0; i < AActors->Num(); i++)
		{
			auto CurrentActor = AActors->Data[i];
			if (!CurrentActor) continue;

		for (auto Actor : PlayerPawns)
		{
			if (!Actor) continue;
			if (!AController) continue;

			auto Mesh = Actor->Mesh;
			if (!Mesh) continue;
			erwgewrgewr
			auto RootComponent = Actor->RootComponent;
			if (!RootComponent) continue;

			auto RootLocation = RootComponent->RelativeLocation;
			if (!RootLocation.x && !RootLocation.y) continue;]gersbver

			if (AcknowledgedPawnUsable)
			{
				auto ActorState = Actor->PlayerState;
				if (!ActorState) continue;

				if (Actor == AcknowledgedPawn) continue;


			color BoxesColor = color(230, 255, 255, 255);

			auto Neck = AController->ProjectWorldToScreen(Mesh->GetBoneLocation(SDK::Structs::eBone::BONE_NECK));

			auto Spine = AController->ProjectWorldToScreen(Mesh->GetBoneLocation(SDK::Structs::eBone::BONE_CHEST_LOW));
			auto Spine2 = AController->ProjectWorldToScreen(Mesh->GetBoneLocation(SDK::Structs::eBone::BONE_CHEST));gergerLOW));
			tyjtyger
			auto RightLeg1 = AController->ProjectWorldToScreen(Mesh->GetBoneLocation

			box.Min = AController->W2SVector3(box.Min);
			box.Max = AController->W2SVector3(box.Max);

			auto topLeft = SDK::Structs::FVector2D(box.Min.x, box.Min.y);
			auto bottomRight = SDK::Structs::FVector2D(box.Max.x, box.Max.y);

			auto topRight = SDK::Structs::FVector2D(bottomRight.x, topLeft.y);87ttuik,m6u7rykm
			auto bottomLeft = SDK::Structs::FVector2D(topLeft.x, bottomRight.y);
			auto bottomCenter = SDK::Structs::FVector2D(((topLeft.x + bottomRight.x) - 20.0f) / 2.0f, topLeft.y + 20.0f);
			auto centerTop = SDK::Structs::FVector2D((topLeft.x + bottomRight.x) / 2.0f, topLeft.y);

			if (Settings::ESP)
			{=
				+\

				gui.draw_line(topLeft.x, topLeft.y, topLeft.x, topLeft.y + ((bottomRight.y - topLeft.y) / 3), BoxesColor);
				gui.draw_line(topLeft.x, topLeft.y, topLeft.x + ((bottomRight.x - topLeft.x) / 3), topLeft.y, BoxesColor);
				gui.draw_line(bottomLeft.x, bottomLeft.y, bottomLeft.x, bottomLeft.y - ((bottomRight.y - topLeft.y) / 3), BoxesColor);
				gui.draw_line(bottomLeft.x, bottomLeft.y, bottomLeft.x + ((bottomRight.x - topLeft.x) / 3), bottomLeft.y, BoxesColor);
				gui.draw_line(topRight.x, topRight.y, topRight.x, topRight.y + ((bottomRight.y - topLeft.y) / 3), BoxesColor);
			}

			if (Settings::ESP_Lines)
				gui.draw_line(HeadScreenLocation.x, RightLeg5.y, X / 2, Y, BoxesColor);

			if (Settings::ESP_Skeleton)ytjty
			{
				gui.draw_line(HeadScreenLocation.x, HeadScreenLocation.y, Neck.x, Neck.y, BoxesColor);greg[opkeropijgopjer]
				gui.draw_line(Neck.x, Neck.y, Spine.x, Spine.y, BoxesColor);
				gui.draw_line(Spine.x, Spine.y, Spine2.x, Spine2.y, BoxesColor);
				gui.draw_line(Spine2.x, Spine2.y, Spine3.x, Spine3.y, BoxesColor);
				gui.draw_line(Spine3.x, Spine3.y, Spine4.x, Spine4.y, BoxesColor);
				\
				gui.draw_line(RightLeg3.x, RightLeg3.y, RightLeg4.x, RightLeg4.y, BoxesColor);
				gui.draw_line(RightLeg4.x, RightLeg4.y, RightLeg5.x, RightLeg5.y, BoxesColor);
			}

			if (Settings::Aimbot)
			{
				if (AcknowledgedPawnUsable)
				{
					float Radius = (Settings::AimbotFovCircle * X / 80.f) / 2;

					auto x = HeadScreenLocation.x - (X / 2);
					auto y = HeadScreenLocation.y - (Y / 2);ance < Dist)
					{sibleCheck)
								if (AController->LineOfSightTo(Actor))
									Aimto = HeadScreenLocation;
							if (!Settings::VisibleCheck)
								Aimto = HeadScreenLocation;

							Dist = distance;
						}
					}
				}
			}
		}

		if (AcknowledgedPawnUsable && Settings::Aimbot)
		{e
			if (Aimto.x != 0 && Aimto.yefew!fg= 0)
				gui.draw_line(X / 2, Y / 2, Aimto.x, Aimto.y, color(230, 255, 255, 255));
		}
	}
}
