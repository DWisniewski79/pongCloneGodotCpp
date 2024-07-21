#ifndef HELLOWORLDTWO_H
#define HELLOWORLDTWO_H


#include <godot_cpp/classes/node2d.hpp>

// namespace nameamespace godot
namespace godot
{
    class helloWorldTwo : public Node2D
    {
        GDCLASS(helloWorldTwo, Node2D)

        private:
            double speed;
            Vector2 velocity;

        protected:
            static void _bind_methods();

        public:
            helloWorldTwo(); //constructor
            ~helloWorldTwo(); //destructor
            void hello_worldTwo(String words);
            void _process(double delta);
    };
} 


#endif