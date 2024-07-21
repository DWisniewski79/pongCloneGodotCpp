#include "register_types.h"
#include "helloWorld.h"
#include "helloWorldTwo.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp> //class definitions
#include <godot_cpp/godot.hpp> // core godot

using namespace godot;

void initialize_hello_world(ModuleInitializationLevel p_level)
{
	//MODULE_INITIALIZATION_LEVEL_SCENE is the stage at which we're going to initialize. Scene is when the godot is actually up and running and initializes the scenes in the editor
	//this means that this code will run when our scene is loaded.
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<helloWorld>();
}

void uninitialize_hello_world(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

void initialize_hello_world_two(ModuleInitializationLevel p_level)
{
	//MODULE_INITIALIZATION_LEVEL_SCENE is the stage at which we're going to initialize. Scene is when the godot is actually up and running and initializes the scenes in the editor
	//this means that this code will run when our scene is loaded.
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<helloWorld>();
}

void uninitialize_hello_world_two(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}



extern "C"
{
	// Initialization
	// This is something called c Linking. It's done in C and not C++ linking.
	// extern C is important because it allows you to access information from both C and C++. Wants to make sure you can use your code easily
	// allows godot to dynamically call this stuff.
	//*IMPORTANT* This method is what is used as the "entry_point" value for a given GDExtension file.
	//A GDExtension file is basically what imports your c++ class into godot, so super important.
	GDExtensionBool GDE_EXPORT hello_world_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
		init_obj.register_initializer(initialize_hello_world);
		init_obj.register_terminator(uninitialize_hello_world);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
	
	//I think that for each c++ script you write, you need to have a separate one of these files to initialize it for godot. And each one will have its own GDExtension file as well.
	GDExtensionBool GDE_EXPORT hello_world_two_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
		init_obj.register_terminator(initialize_hello_world_two);
		init_obj.register_terminator(uninitialize_hello_world_two);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}