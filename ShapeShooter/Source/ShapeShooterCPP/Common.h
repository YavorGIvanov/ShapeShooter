#pragma once
#include "World.h"

namespace godot
{
namespace Common
{
enum class Shape
{
	Triangle,
	Square,
	Pentagon,
	Shape_Count
};

static const unsigned SCREEN_WIDTH = 1280;
static const unsigned SCREEN_HEIGHT = 720;
static const unsigned SHAPE_COUNT = static_cast<unsigned>(Shape::Shape_Count);

static godot::String ConvertShapeToString(Shape shape)
{
	static_assert(static_cast<unsigned>(Shape::Triangle) == 0
		&& static_cast<unsigned>(Shape::Square) == 1
		&& static_cast<unsigned>(Shape::Pentagon) == 2,
		"Invalid Shape to String mapping");

	static const godot::String shapeToStringMapping[SHAPE_COUNT] =
	{
		"Triangle",
		"Square",
		"Pentagon"
	};

	return shapeToStringMapping[static_cast<unsigned>(shape)];
}

static godot::String ConvertShapeToColorString(Shape shape)
{
	static_assert(static_cast<unsigned>(Shape::Triangle) == 0
		&& static_cast<unsigned>(Shape::Square) == 1
		&& static_cast<unsigned>(Shape::Pentagon) == 2,
		"Invalid Shape to Color String mapping");

	static const godot::String shapeToColorStringMapping[SHAPE_COUNT] =
	{
		"green",
		"blue",
		"red"
	};

	return shapeToColorStringMapping[static_cast<unsigned>(shape)];
}

}
}