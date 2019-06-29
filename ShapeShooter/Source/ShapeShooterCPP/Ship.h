#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>

namespace godot
{

class Ship : public KinematicBody2D
{
	GODOT_CLASS(Ship, KinematicBody2D)
public:
	const int SPEED = 250;

	static void _register_methods();
	void _init();
	void _process(float delta);
	void _ready();

	Ship();
	~Ship();

	void UpdateMotionFromInput();
private:
	Vector2 m_Motion;
};

}