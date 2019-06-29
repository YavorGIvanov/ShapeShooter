//#pragma once
//
//#include <core/Godot.hpp>
//#include <Node2D.hpp>
//
//namespace godot 
//{
//enum class AsteroidShapes
//{
//	Triangle,
//	Square,
//	Pentagon,
//	Shape_Count
//};
//
//class AsteroidGenerator : public Node2D
//{
//	GODOT_CLASS(AsteroidGenerator, Node2D)
//public:
//	static const uint32_t SHAPE_COUNT = static_cast<unsigned>(AsteroidShapes::Shape_Count);
//	static const godot::String m_ShapeToStringMapping[SHAPE_COUNT];
//
//	static void _register_methods();
//	void _ready();
//	void _init();
//
//	AsteroidGenerator();
//	~AsteroidGenerator();
//private:
//};
//}