#include "Bullet.h"
#include "Common.h"

using namespace godot;

int Bullet::m_Velocity = 230;
float Bullet::m_RotationStep = 0.75;

void Bullet::_register_methods()
{
	register_method("_ready", &Bullet::_ready);
	register_method("_process", &Bullet::_process);
}

void Bullet::_init()
{}

void Bullet::_ready()
{
	set_rotation_degrees(rand() % 360);
}

void Bullet::_process(float delta)
{
	UpdatePosition(delta);
}

Bullet::Bullet()
{}

Bullet::~Bullet()
{}

void Bullet::UpdatePosition(float delta)
{
	move_and_slide(Vector2(m_Velocity, 0));
	set_rotation_degrees(get_rotation_degrees() + m_RotationStep);

	if (get_global_position().x > Common::SCREEN_WIDTH)
	{
		queue_free();
		return;
	}

}
