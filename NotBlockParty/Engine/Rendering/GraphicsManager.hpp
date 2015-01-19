#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <vector>
#include <SFML\Graphics.hpp>

#include "..\Messaging\MessageBus.hpp"
#include "..\Rendering\RenderMessages.hpp"
#include "..\State\StateMessages.hpp"

class GraphicsManager : MessageReceiver<RegisterDrawable, DrawMessage> {
	public:
	void HandleMessage( const RegisterDrawable& message );
	void HandleMessage( const DrawMessage& message );

	private:
	void Draw( sf::RenderWindow* window );

	std::vector<sf::Drawable*> drawables;

};

#endif // GRAPHICSMANAGER_H