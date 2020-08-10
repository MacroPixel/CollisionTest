#ifndef DYNAMIC_H
#define DYNAMIC_H
#include "HeaderMain.h"

class Solid;

class Dynamic
{
public:
        static std::vector<Dynamic*> objects;

        sf::RectangleShape body;
        float positionX; float positionY;
        float originX; float originY;
        float sizeX; float sizeY;
        sf::Color color;

        Dynamic( sf::Vector2f t_position, sf::Vector2f t_size, sf::Vector2f t_origin, sf::Color t_color );
        void draw( sf::RenderWindow& window );
        void update( float deltaTime );
        bool checkCollision( Solid& solid );
};

#endif // DYNAMIC_H
