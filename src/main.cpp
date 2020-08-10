#include "HeaderMain.h"
#include "Solid.h"
#include "Dynamic.h"
#include "Functions1.h"

// STATIC VARIABLES

std::vector<Solid*> Solid::objects{};
std::vector<Dynamic*> Dynamic::objects{};

int main()
{
        // CONFIGURE WINDOW

        sf::RenderWindow window{ sf::VideoMode( 1280, 720 ), "C++/SFML.cpp" };
        window.setFramerateLimit( 60 );

        // CONFIGURE OBJECTS

        new Solid{ sf::Vector2f{ 640, 360 }, sf::Vector2f{ 100, 100 }, sf::Vector2f{ 50, 50 }, sf::Color::Red };
        new Solid{ sf::Vector2f{ 690, 410 }, sf::Vector2f{ 100, 100 }, sf::Vector2f{ 50, 50 }, sf::Color::Red };
        new Solid{ sf::Vector2f{ 640, 150 }, sf::Vector2f{ 100, 100 }, sf::Vector2f{ 50, 50 }, sf::Color::Red };
        new Dynamic{ sf::Vector2f{ 900, 360 }, sf::Vector2f{ 100, 100 }, sf::Vector2f{ 50, 50 }, sf::Color::Green };

        // OTHER STUFF
        float deltaTime;
        sf::Clock clock;

        while ( window.isOpen() )
        {
                // DELTA TIME
                deltaTime = clock.restart().asSeconds();

                sf::Event event;
                while ( window.pollEvent( event ) )
                {
                        switch ( event.type )
                        {
                                case sf::Event::Closed:
                                        window.close();
                                        break;
                                default:
                                        break;
                        }
                }

                window.clear();

                f1::updateObjects( deltaTime );

//                std::cout << ( rofl.checkCollision( rofll ) ? "True" : "False" ) << '\n';

                f1::drawObjects( window );

                window.display();
        }

        return 0;
}
