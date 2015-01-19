#ifndef BASETILEMAP_H
#define BASETILEMAP_H

#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include <Thor\Resources.hpp>

class BaseTileMap {
	public:
	BaseTileMap( const sf::Vector2u& mapSize, const sf::Vector2u& tileSize );

	const std::vector<int>& GetTileMap() const;
	std::weak_ptr<sf::Texture> GetTileSet() const;

	const sf::Vector2u& GetMapSize() const;
	const sf::Vector2u& GetTileSize() const;

	protected:
	sf::Vector2u mapSize;
	sf::Vector2u tileSize;

	std::vector<int> tileMap;
	std::shared_ptr<sf::Texture> tileSet;

};

#endif // BASETILEMAP_H