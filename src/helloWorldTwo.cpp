#include "helloWorldTwo.h"
#include <godot_cpp/core/class_db.hpp> //I'm guessing used for storing data in some sort of godot db?
#include <godot_cpp/godot.hpp> //general godot stuff. Used so that we can actually use godot
#include <godot_cpp/variant/utility_functions.hpp> // used for being able to print
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void helloWorldTwo::_bind_methods()
{

}

helloWorldTwo::helloWorldTwo()
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("Hello Davey!");

}

helloWorldTwo::~helloWorldTwo()
{

}

void helloWorldTwo::hello_worldTwo(String words)
{

}


void helloWorldTwo::_process(double delta)
{
    UtilityFunctions::print("Hey Davey, this is your process speaking");

}