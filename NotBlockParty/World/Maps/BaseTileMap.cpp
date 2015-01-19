#include "BaseTileMap.hpp"

BaseTileMap::BaseTileMap( const sf::Vector2u& mapSize, const sf::Vector2u& tileSize ) : mapSize( mapSize ), tileSize( tileSize ) { 

}

const std::vector<int>& BaseTileMap::GetTileMap() const {
	return tileMap;
}

std::weak_ptr<sf::Texture> BaseTileMap::GetTileSet() const {
	return tileSet;
}

const sf::Vector2u& BaseTileMap::GetMapSize() const {
	return mapSize;
}

const sf::Vector2u& BaseTileMap::GetTileSize() const {
	return tileSize;
}