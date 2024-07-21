#ifndef HELLOWORLD_H
#define HELLOWORLD_H


#include <godot_cpp/classes/node2d.hpp>

// namespace nameamespace godot
namespace godot
{
    class helloWorld : public Node2D
    {
        GDCLASS(helloWorld, Node2D)

        private:
            double speed;
            Vector2 velocity;

        protected:
            static void _bind_methods();

        public:
            helloWorld(); //constructor
            ~helloWorld(); //destructor
            void hello_world(String words);
            void _process(double delta);
            void set_speed(const double speed);
            double get_speed() const;
    };
} 


#endif