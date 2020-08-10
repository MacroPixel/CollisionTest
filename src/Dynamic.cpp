#include "Dynamic.h"
#include "Solid.h"

Dynamic::Dynamic( sf::Vector2f t_position, sf::Vector2f t_size, sf::Vector2f t_origin, sf::Color t_color ) :
        body{ t_size },
                positionX{ t_position.x }, positionY{ t_position.y }, originX{ t_origin.x }, originY{ t_origin.y }, sizeX{ t_size.x }, sizeY{ t_size.y }, color{ t_color }
{
        // setup rectangle body
        body.setPosition( t_position );
        body.setOrigin( t_origin );
        body.setFillColor( color );

        // keep track of object
        Dynamic::objects.push_back( this );
}

void Dynamic::draw( sf::RenderWindow& window )
{
        window.draw( body );
}

void Dynamic::update( float deltaTime )
{
        // [H] keyboard input
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
                positionX += 500 * deltaTime;
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
                positionX -= 500 * deltaTime;

        // [H] collision handling
        for( auto solidPtr : Solid::objects )
        {
                if ( checkCollision( *solidPtr ) )
                {
                        if ( positionX < solidPtr->positionX )
                                positionX = ( solidPtr->positionX - solidPtr->originX - sizeX + originX );
                        else
                                positionX = ( solidPtr->positionX - solidPtr->originX + solidPtr->sizeX + originX );
                }
        }

        // [V]  keyboard input
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
                positionY += 500 * deltaTime;
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
                positionY -= 500 * deltaTime;

        // [V] collision handling
        for( auto solidPtr : Solid::objects )
        {
                if ( checkCollision( *solidPtr ) )
                {
                        if ( positionY < solidPtr->positionY )
                                positionY = ( solidPtr->positionY - solidPtr->originY - sizeY + originY );
                        else
                                positionY = ( solidPtr->positionY - solidPtr->originY + solidPtr->sizeY + originY );
                }
        }

        // update geometry
        body.setPosition( positionX, positionY );
}

bool Dynamic::checkCollision( Solid& solid )
{
        float deltaX = abs( positionX - solid.positionX );
        float deltaY = abs( positionY - solid.positionY );

        float resX = deltaX - ( ( sizeX + solid.sizeX ) / 2 );
        float resY = deltaY - ( ( sizeY + solid.sizeY ) / 2 );

        return ( resX < 0 && resY < 0 );
}
