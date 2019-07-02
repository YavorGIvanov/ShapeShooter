#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include <TextureRect.hpp>
#include "Common.h"
#include "AsteroidGenerator.h"
#include <chrono>

namespace godot
{

class World : public Node2D
{
	GODOT_CLASS(World, Node2D)
public:
	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);

	World();
	~World();

	void ChangeLevel();
private:
	static const int m_LevelChangeSeconds = 15;
	std::chrono::high_resolution_clock::time_point m_StartTimePoint;
	CanvasItem* m_DeathScreen;
	Node2D* m_AsteroidGenerator;
	TextureRect* m_Background;
};

}