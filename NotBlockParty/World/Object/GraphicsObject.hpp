#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <SFML\Graphics.hpp>

class GraphicsObject : public sf::Drawable {
	public:


	private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	// Texture is saved on the GPU
	// It shouldn't be manipulated. Manipulate via sprite if need be.
	sf::Texture texture;

	// Sprite made from the texture.
	sf::Sprite sprite;

	// The size rect of the tile.
	// Always 0, 0, TILE_SIZE, TILE_SIZE
	sf::IntRect rect;
};

#endif // GRAPHICSOBJECT_H