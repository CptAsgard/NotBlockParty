#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <SFML\Graphics.hpp>

class GraphicsObject : public sf::Drawable {
	private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

};

#endif // GRAPHICSOBJECT_H