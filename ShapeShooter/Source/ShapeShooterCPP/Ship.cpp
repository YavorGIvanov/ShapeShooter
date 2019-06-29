#include "Ship.h"

using namespace godot;

void Ship::_register_methods()
{
	register_method("_process", &Ship::_process);
	register_method("_ready", &Ship::_ready);
}

void Ship::_init() {}

Ship::Ship()
	: m_Motion(0, 0)
{
}

Ship::~Ship() {}

void Ship::_process(float delta)
{
	UpdateMotionFromInput();
	move_and_slide(m_Motion);
}

void Ship::_ready()
{

}

void Ship::UpdateMotionFromInput() {
	m_Motion = Vector2(0, 0);
	auto inputSingleton = Input::get_singleton();

	if (inputSingleton->is_action_pressed("ui_up"))
	{
		m_Motion.y -= SPEED;
	}

	if (inputSingleton->is_action_pressed("ui_down"))
	{
		m_Motion.y += SPEED;
	}

	if (inputSingleton->is_action_pressed("ui_left"))
	{
		m_Motion.x -= SPEED;
	}

	if (inputSingleton->is_action_pressed("ui_right"))
	{
		m_Motion.x += SPEED;
	}
}