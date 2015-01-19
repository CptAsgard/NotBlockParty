#include "GraphicsManager.hpp"

void GraphicsManager::HandleMessage( const RegisterDrawable& message ) {
	drawables.push_back( message.renderable );
}

void GraphicsManager::HandleMessage( const DrawMessage& message ) {
	Draw( message.window );
}

void GraphicsManager::Draw( sf::RenderWindow* window ) {
	std::cout << "lel";

	for each( sf::Drawable* p in drawables ) {
		if( p != nullptr )
			window->draw( *p );
	}
}