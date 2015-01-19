#ifndef TILERENDERER_H
#define TILERENDERER_H

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "..\..\Engine\State\StateManager.hpp"
#include "..\..\Engine\State\StateMessages.hpp"
#include "..\WorldMessages.hpp"
#include "BaseTileMap.hpp"

/**
 * TileMapRenderer can draw a array of tiles
 * http://www.sfml-dev.org/tutorials/2.2/graphics-vertex-array.php
 * http://www.optank.org/2013/02/10/game-development-design-2-good-habits-techniques-and-workflows/
 * https://github.com/Nyrox/SFFP/blob/master/SFFP/SFFP.cpp && http://pastebin.com/gcWJCJQ8
 */
class TileMapRenderer : public sf::Drawable, public sf::Transformable {
	public:
	TileMapRenderer( StateManager* stateManager ) : stateManager( stateManager ) {
		stateManager->GetMessageBus()->Send( RegisterDrawable{this} );
	}

	bool Load( const BaseTileMap& tileMap );

	private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

	sf::VertexArray vertices;

	std::weak_ptr<sf::Texture> tileset;
	StateManager* stateManager;
};

#endif // TILERENDERER_H