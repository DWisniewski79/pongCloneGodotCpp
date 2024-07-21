#include "helloWorld.h"
#include <godot_cpp/core/class_db.hpp> //I'm guessing used for storing data in some sort of godot db?
#include <godot_cpp/godot.hpp> //general godot stuff. Used so that we can actually use godot
#include <godot_cpp/variant/utility_functions.hpp> // used for being able to print
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/input.hpp>

using namespace godot;

void helloWorld::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_speed"), &helloWorld::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &helloWorld::set_speed);
    ClassDB::add_property("helloWorld", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("hello_world", "words"), &helloWorld::hello_world);

}

helloWorld::helloWorld()
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
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
    velocity = Vector2(0.0f, 0.0f);

    Input& inputSingleton = *Input::get_singleton();


    if(inputSingleton.is_action_pressed("d"))
    {
        velocity.x += 1.0f;
    }

     if(inputSingleton.is_action_pressed("a"))
    {
        velocity.x -= 1.0f;
    } 
    
    if(inputSingleton.is_action_pressed("w"))
    {
        velocity.y += 1.0f;
    }
    
    if(inputSingleton.is_action_pressed("s"))
    {
        velocity.y -= 1.0f;
    }

    set_position(get_position() + (velocity * speed * delta));
}


void helloWorld::set_speed(const double speed)
{
    this->speed = speed;
}

double helloWorld::get_speed() const
{
    return speed;
}