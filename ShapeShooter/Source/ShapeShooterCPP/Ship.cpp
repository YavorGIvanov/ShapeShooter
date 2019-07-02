#include "Ship.h"
#include <Resource.hpp>
#include <ResourceLoader.hpp>
#include <cassert>
#include <Texture.hpp>

using namespace godot;
using namespace Common;

void Ship::_register_methods()
{
	register_method("_process", &Ship::_process);
	register_method("_ready", &Ship::_ready);
}

void Ship::_init()
{
	set_name("Ship");
}

Ship::Ship()
{}

Ship::~Ship() {}

void Ship::_process(float delta)
{
	HandleInput(delta);
}

void Ship::_ready()
{
	m_TriangleBullet = ResourceLoader::get_singleton()->load("res://TriangleBullet.tscn");
	assert(m_TriangleBullet.is_valid());

	m_SquareBullet = ResourceLoader::get_singleton()->load("res://SquareBullet.tscn");
	assert(m_SquareBullet.is_valid());

	m_PentagonBullet = ResourceLoader::get_singleton()->load("res://PentagonBullet.tscn");
	assert(m_PentagonBullet.is_valid());

	const auto shipChildrenCount = get_child_count();

	for (int i = 0; i < shipChildrenCount; ++i)
	{
		auto child = get_child(i);

		if (child->get_name() == "CollisionPolygon2D")
		{
			m_Sprite = static_cast<Sprite*>(child->get_child(0));
		}
	}

	assert(m_Sprite);
}

void Ship::HandleInput(float delta)
{
	auto inputSingleton = Input::get_singleton();

	UpdateMotionFromInput(delta, inputSingleton);

	if (inputSingleton->is_action_just_pressed("ship_fire"))
	{
		ShootBullet();
	}
}

void Ship::UpdateMotionFromInput(float delta, const Input* inputSingleton)
{
	Vector2 motion(0, 0);
	if (inputSingleton->is_action_pressed("ui_up"))
	{
		motion.y -= delta*VELOCITY;
	}

	if (inputSingleton->is_action_pressed("ui_down"))
	{
		motion.y += delta*VELOCITY;
	}

	if (inputSingleton->is_action_pressed("ui_left"))
	{
		motion.x -= delta*VELOCITY;
	}

	if (inputSingleton->is_action_pressed("ui_right"))
	{
		motion.x += delta*VELOCITY;
	}

	move_and_slide(motion);
}

void Ship::ShootBullet()
{
	Node2D* bullet = nullptr;
	Shape bulletShape = Shape::Triangle;

	for (int i = 0; i < SHAPE_COUNT; ++i)
	{
		const auto shape = static_cast<Shape>(i);
		const auto colorString = ConvertShapeToColorString(shape);
		if (m_Sprite->get_texture()->get_path().find(colorString) != -1)
		{
			bulletShape = shape;
		}
	}

	if (bulletShape == Shape::Triangle)
	{
		bullet = static_cast<Node2D*>(m_TriangleBullet->instance());
	}
	else if (bulletShape == Shape::Square)
	{
		bullet = static_cast<Node2D*>(m_SquareBullet->instance());

	}
	else if (bulletShape == Shape::Pentagon)
	{
		bullet = static_cast<Node2D*>(m_PentagonBullet->instance());
	}
	else
	{
		assert(false && "Invalid Ship Shape");
		return;
	}

	bullet->set_global_position(get_global_position() + Vector2(15, -15));
	get_parent()->add_child(bullet);
}
