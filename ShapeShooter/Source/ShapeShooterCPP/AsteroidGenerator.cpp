#include "AsteroidGenerator.h"
#include "Asteroid.h"
#include "Common.h"
#include <Resource.hpp>
#include <ResourceLoader.hpp>
#include <cassert>

using namespace godot;
using namespace Common;

float AsteroidGenerator::m_DeltaSumLimit = 0.15;

void AsteroidGenerator::_register_methods()
{
	register_method("_ready", &AsteroidGenerator::_ready);
	register_method("_process", &AsteroidGenerator::_process);
}


void AsteroidGenerator::_init() {}

void AsteroidGenerator::_ready()
{
	m_TriangleAsteroid = ResourceLoader::get_singleton()->load("res://TriangleAsteroid.tscn");
	assert(m_TriangleAsteroid.is_valid());

	m_SquareAsteroid = ResourceLoader::get_singleton()->load("res://SquareAsteroid.tscn");
	assert(m_SquareAsteroid.is_valid());

	m_PentagonAsteroid = ResourceLoader::get_singleton()->load("res://PentagonAsteroid.tscn");
	assert(m_PentagonAsteroid.is_valid());
}

void AsteroidGenerator::_process(float delta)
{
	m_DeltaSum += delta;

	if (m_DeltaSum < m_DeltaSumLimit)
	{
		return;
	}
	else
	{
		m_DeltaSum = 0;
	}

	Node2D* asteroid = nullptr;
	if (m_CurrentShape == static_cast<unsigned>(Shape::Triangle))
	{
		asteroid = static_cast<Node2D*>(m_TriangleAsteroid->instance());
	}
	else if (m_CurrentShape == static_cast<unsigned>(Shape::Square))
	{
		asteroid = static_cast<Node2D*>(m_SquareAsteroid->instance());

	}
	else if (m_CurrentShape == static_cast<unsigned>(Shape::Pentagon))
	{
		asteroid = static_cast<Node2D*>(m_PentagonAsteroid->instance());
	}
	else
	{
		assert(false && "Invalid Asteroid Shape");
		return;
	}

	asteroid->set_global_position(Vector2(SCREEN_WIDTH, m_Distribution(m_RandomGenerator)));
	get_parent()->add_child(asteroid);

	if (m_Distribution(m_RandomGenerator) % 3 == 0)
	{
		UpdateCurrentShape();
	}
}

AsteroidGenerator::AsteroidGenerator()
	: m_DeltaSum(0)
{
	std::random_device randomDevice;
	m_RandomGenerator.seed(randomDevice());
	m_Distribution = std::uniform_int_distribution<>(Asteroid::HEIGHT / 3, SCREEN_HEIGHT - Asteroid::HEIGHT / 3);
}

AsteroidGenerator::~AsteroidGenerator()
{}

void AsteroidGenerator::UpdateCurrentShape()
{
	m_CurrentShape = m_Distribution(m_RandomGenerator) % 3;
}
