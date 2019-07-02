#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <TextureRect.hpp>
#include <Sprite.hpp>
#include <Texture.hpp>
#include <Reference.hpp>

namespace godot
{
class ShapeChanger : public Node2D {
	GODOT_CLASS(ShapeChanger, Node2D)
public:
	ShapeChanger();
	~ShapeChanger();
	static void _register_methods();
	void _init();
	void _ready();
	void _on_Area2D_body_entered(Variant body);
private:
	Sprite* m_ShipSprite;
	Ref<Texture> m_Texture;
};
}