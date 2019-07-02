#include "Asteroid.h"
#include "Common.h"
#include "Bullet.h"
#include <KinematicCollision2D.hpp>
#include <SceneTree.hpp>

using namespace godot;
using namespace Common;

int Asteroid::m_Velocity = 180;
float Asteroid::m_RotationStep = 75;

void Asteroid::_register_methods()
{
	register_method("_ready", &Asteroid::_ready);
	register_method("_process", &Asteroid::_process);
}

void Asteroid::_init()
{}

void Asteroid::_ready()
{
	set_rotation_degrees(rand() % 360);
}

void Asteroid::_process(float delta)
{
	UpdatePosition(delta);
	HandleCollision();
}

Asteroid::Asteroid()
{}

Asteroid::~Asteroid()
{}

void Asteroid::UpdatePosition(float delta)
{
	move_and_slide(Vector2(-m_Velocity, 0));
	set_rotation_degrees(get_rotation_degrees() + delta * m_RotationStep);
}

void Asteroid::HandleCollision()
{
	bool shouldRemoveAsteroid = get_global_position().x < 0;

	const auto collisionCount = get_slide_count();
	for (int i = 0; i < collisionCount; ++i)
	{
		bool bulletCollision = false;
		const auto collider = static_cast<Node2D*>(get_slide_collision(i)->get_collider());
		const auto colliderFilename = collider->get_filename();
		const auto asteroidFilename = get_filename();

		for (int j = 0; j < SHAPE_COUNT; ++j)
		{
			const auto shape = static_cast<Shape>(j);
			const auto shapeString = ConvertShapeToString(shape);

			if (colliderFilename.find(shapeString) != -1 && asteroidFilename.find(shapeString) != -1)
			{
				bulletCollision = true;
				break;
			}
		}

		if (bulletCollision)
		{
			collider->queue_free();
			shouldRemoveAsteroid = true;
		}
		else if (collider->get_name() == "Ship")
		{
			get_parent()->get_tree()->quit();
		}
	}

	if (shouldRemoveAsteroid)
	{
		queue_free();
	}
}
