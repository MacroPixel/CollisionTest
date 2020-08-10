#include "HeaderMain.h"
#include "Solid.h"
#include "Dynamic.h"

namespace f1
{
        void drawObjects( sf::RenderWindow& window )
        {
                for( Solid* solidPtr : Solid::objects )
                        solidPtr->draw( window );
                for( Dynamic* dynamicPtr : Dynamic::objects )
                        dynamicPtr->draw( window );
        }

        void updateObjects( float deltaTime )
        {
                for( Dynamic* dynamicPtr : Dynamic::objects )
                        dynamicPtr->update( deltaTime );
        }
}
