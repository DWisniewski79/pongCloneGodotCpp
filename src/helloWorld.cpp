#include "helloWorld.h"
#include <godot_cpp/core/class_db.hpp> //I'm guessing used for storing data in some sort of godot db?
#include <godot_cpp/godot.hpp> //general godot stuff. Used so that we can actually use godot
#include <godot_cpp/variant/utility_functions.hpp> // used for being able to print

using namespace godot;

void helloWorld::_bind_methods()
{

}

helloWorld::helloWorld()
{
    UtilityFunctions::print("Hello Davey!");

}

helloWorld::~helloWorld()
{

}

void helloWorld::hello_world(String words)
{

}


void helloWorld::_process(double delta)
{
    UtilityFunctions::print("Hey Davey, this is your process speaking");

}