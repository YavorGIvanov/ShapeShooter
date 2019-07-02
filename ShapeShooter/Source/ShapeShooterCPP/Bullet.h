#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include "Common.h"

namespace godot
{

class Bullet : public KinematicBody2D
{
	GODOT_CLASS(Bullet, KinematicBody2D)
public:
	static int m_Velocity;
	static float m_RotationStep;

	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);
	
	Bullet();
	~Bullet();

	void UpdatePosition(float delta);
private:
	Common::Shape m_Shape;
};

}