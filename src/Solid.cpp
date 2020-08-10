#include "Solid.h"

Solid::Solid( sf::Vector2f t_position, sf::Vector2f t_size, sf::Vector2f t_origin, sf::Color t_color ) :
        body{ t_size },
                positionX{ t_position.x }, positionY{ t_position.y }, originX{ t_origin.x }, originY{ t_origin.y }, sizeX{ t_size.x }, sizeY{ t_size.y }, color{ t_color }
{
        // setup rectangle body
        body.setPosition( t_position );
        body.setOrigin( t_origin );
        body.setFillColor( color );

        // keep track of object
        Solid::objects.push_back( this );
}

void Solid::draw( sf::RenderWindow& window )
{
        window.draw( body );
}
