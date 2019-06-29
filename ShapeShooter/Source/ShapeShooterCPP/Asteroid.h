//#pragma once
//
//#include <core/Godot.hpp>
//#include <Node2D.hpp>
//#include <core/Ref.hpp>
//#include <PackedScene.hpp>
//
//namespace godot
//{
//class Asteroid
//{
//public:
//	enum Shape
//	{
//		Triangle,
//		Square,
//		Pentagon,
//		Shape_Count
//	};
//	static const godot::String m_ShapeToStringMapping[Shape::Shape_Count];
//
//	Asteroid(Shape shape);
//	~Asteroid();
//
//	const Node2D* GetInstance() const;
//	Shape GetShape() const;
//
//	void UpdatePosition();
//	void UpdateRotation();
//private:
//	godot::Ref<PackedScene> m_Scene;
//	Node2D* m_Instance;
//	Shape m_Shape;
//	Vector2 m_Position;
//	Vector2 m_Rotation;
//};
//}