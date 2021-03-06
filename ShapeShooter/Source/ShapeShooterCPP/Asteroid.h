#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include "Common.h"

namespace godot
{

class Asteroid : public KinematicBody2D
{
	GODOT_CLASS(Asteroid, KinematicBody2D)
public:
	static const int WIDTH = 68;
	static const int HEIGHT = 68;
	
	static int m_Velocity;
	static float m_RotationStep;

	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);

	Asteroid();
	~Asteroid();

	void UpdatePosition(float delta);
	void HandleCollision();
};

}