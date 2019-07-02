#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include <core/Ref.hpp>
#include <PackedScene.hpp>
#include <Input.hpp>
#include "Common.h"
#include <Sprite.hpp>

namespace godot
{

class Ship : public KinematicBody2D
{
	GODOT_CLASS(Ship, KinematicBody2D)
public:
	const int VELOCITY = 12500;

	static void _register_methods();
	void _init();
	void _process(float delta);
	void _ready();

	Ship();
	~Ship();

	void HandleInput(float delta);
	void UpdateMotionFromInput(float delta, const Input* inputSingleton);
	void ShootBullet();
private:
	godot::Ref<PackedScene> m_TriangleBullet;
	godot::Ref<PackedScene> m_SquareBullet;
	godot::Ref<PackedScene> m_PentagonBullet;
	Sprite* m_Sprite;
};

}