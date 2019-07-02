#include "ShapeChanger.h"
#include "Common.h"
#include <cassert>
#include <ResourceLoader.hpp>

using namespace godot;
using namespace Common;

void ShapeChanger::_register_methods()
{
	register_method("_ready", &ShapeChanger::_ready);
	register_method("_on_Area2D_body_entered", &ShapeChanger::_on_Area2D_body_entered);
}

void ShapeChanger::_init()
{
}

void ShapeChanger::_ready()
{
	Node2D* shipNode = nullptr;
	int64_t childCount = get_parent()->get_child_count();
	for (int64_t i = 0; i < childCount; ++i)
	{
		auto child = get_parent()->get_child(i);
		if (child->get_name() == "Ship")
		{
			shipNode = static_cast<Node2D*>(child);
		}
	}
	assert(shipNode);

	const auto shipChildrenCount = shipNode->get_child_count();

	for (int i = 0; i < shipChildrenCount; ++i)
	{
		auto child = shipNode->get_child(i);

		if (child->get_name() == "CollisionPolygon2D")
		{
			m_ShipSprite = static_cast<Sprite*>(child->get_child(0));
		}
	}

	for (int i = 0; i < SHAPE_COUNT; ++i)
	{
		const auto shape = static_cast<Shape>(i);
		const auto shapeString = ConvertShapeToString(shape);
		if (get_filename().find(shapeString) != -1)
		{
			const auto colorString = ConvertShapeToColorString(shape);
			const auto shipImageName = "res://assets/images/" + colorString + "_ship.png";
			m_Texture = ResourceLoader::get_singleton()->load(shipImageName);
		}
	}

	assert(m_ShipSprite && m_Texture.is_valid());
}

void ShapeChanger::_on_Area2D_body_entered(Variant body)
{
	m_ShipSprite->set_texture(m_Texture);
}

ShapeChanger::ShapeChanger()
	: m_ShipSprite(nullptr)
{}

ShapeChanger::~ShapeChanger()
{}