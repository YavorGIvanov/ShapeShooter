#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <core/Ref.hpp>
#include <PackedScene.hpp>
#include <random>
#include "Common.h"

namespace godot 
{
class AsteroidGenerator : public Node2D
{
	GODOT_CLASS(AsteroidGenerator, Node2D)
public:
	static float m_DeltaSumLimit;

	static void _register_methods();
	void _init();
	void _ready();
	void _process(float delta);

	AsteroidGenerator();
	~AsteroidGenerator();

	void UpdateCurrentShape();
private:
	float m_DeltaSum;
	int m_CurrentShape;
	std::mt19937 m_RandomGenerator;
	std::uniform_int_distribution<> m_Distribution;

	godot::Ref<PackedScene> m_TriangleAsteroid;
	godot::Ref<PackedScene> m_SquareAsteroid;
	godot::Ref<PackedScene> m_PentagonAsteroid;
};
}