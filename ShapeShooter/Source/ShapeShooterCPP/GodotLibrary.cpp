#include "Ship.h"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options* initOptions)
{
	Godot::gdnative_init(initOptions);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options* terminateOptions)
{
	Godot::gdnative_terminate(terminateOptions);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle)
{
	Godot::nativescript_init(handle);
	register_class<Ship>();
}