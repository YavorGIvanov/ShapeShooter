#include "World.h"

using namespace godot;

void World::_register_methods()
{
	register_method("_ready", &World::_ready);
	register_method("_process", &World::_process);
}

void World::_init()
{
}

void World::_ready()
{
	//m_StartTimePoint(std::chrono::high_resolution_clock::now())

	int64_t childCount = get_child_count();
	for (int64_t i = 0; i < childCount; ++i)
	{
		auto child = get_child(i);
		const auto childName = child->get_name();
		if (childName == "CanvasLayer")
		{
			m_DeathScreen = static_cast<CanvasItem*>(child);
		}
		else if (childName == "AsteroidGenerator")
		{
			m_AsteroidGenerator = static_cast<Node2D*>(child);
		}
		else if (childName == "Background")
		{
			m_Background = static_cast<TextureRect*>(child);
		}
		else if (childName == "Ship")
		{
			//m_Ship = static_cast<Node2D*>(child);
		}
	}

}

void World::_process(float delta)
{
	//std::chrono::high_resolution_clock::time_point currentTimePoint = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<double, std::chrono::seconds> timePointDiff = currentTimePoint - m_StartTimePoint;
	//auto secondsDiff = std::chrono::duration_cast<std::chrono::duration<std::chrono::seconds>>(timePointDiff.count());

	//if (secondsDiff > m_LevelChangeSeconds)
	//{
	//	ChangeLevel();
	//}
}

World::World()
{
}

World::~World()
{
}

void World::ChangeLevel()
{
}
