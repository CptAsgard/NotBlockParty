#include "TileMapRenderer.hpp"

bool TileMapRenderer::Load( const BaseTileMap& tileMap ) {
	stateManager->GetMessageBus()->Send( MapLoadRequested{} );

	unsigned int width = tileMap.GetMapSize().x;
	unsigned int height = tileMap.GetMapSize().y;

	sf::Vector2u tileSize = tileMap.GetTileSize();

	tileset = tileMap.GetTileSet();
	sf::Vector2u mapSize = tileset.lock()->getSize();

	// resize the vertex array to fit the level size
	vertices.setPrimitiveType( sf::Quads );
	vertices.resize( width * height * 4 );

	// populate the vertex array, with one quad per tile
	for( unsigned int i = 0; i < width; ++i )
		for( unsigned int j = 0; j < height; ++j ) {
			// get the current tile number
			int tileNumber = tileMap.GetTileMap()[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (mapSize.x / tileSize.x);
			int tv = tileNumber / (mapSize.x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f( i * tileSize.x, j * tileSize.y );
			quad[1].position = sf::Vector2f( (i + 1) * tileSize.x, j * tileSize.y );
			quad[2].position = sf::Vector2f( (i + 1) * tileSize.x, (j + 1) * tileSize.y );
			quad[3].position = sf::Vector2f( i * tileSize.x, (j + 1) * tileSize.y );

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f( tu * tileSize.x, tv * tileSize.y );
			quad[1].texCoords = sf::Vector2f( (tu + 1) * tileSize.x, tv * tileSize.y );
			quad[2].texCoords = sf::Vector2f( (tu + 1) * tileSize.x, (tv + 1) * tileSize.y );
			quad[3].texCoords = sf::Vector2f( tu * tileSize.x, (tv + 1) * tileSize.y );
		}

	stateManager->GetMessageBus()->Send( MapLoadSuccessful{} );
	return true;
}


void TileMapRenderer::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
	 // apply the transform
	 states.transform *= getTransform();

	 if( tileset.expired() )
		 std::cout << "wut";

	 // apply the tileset texture
	 states.texture = &(*tileset.lock());

	 // draw the vertex array
	 target.draw( vertices, states );
}