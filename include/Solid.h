#ifndef SOLID_H
#define SOLID_H
#include "HeaderMain.h"


class Solid
{
public:
        static std::vector<Solid*> objects;

        sf::RectangleShape body;
        float positionX; float positionY;
        float originX; float originY;
        float sizeX; float sizeY;
        sf::Color color;

        Solid( sf::Vector2f t_position, sf::Vector2f t_dimensions, sf::Vector2f t_origin, sf::Color t_color );
        void draw( sf::RenderWindow& window );
};

#endif // SOLID_H
