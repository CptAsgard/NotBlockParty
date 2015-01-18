#ifndef BASETILEMAP_H
#define BASETILEMAP_H

#include <vector>

class BaseTileMap {
	public:
	BaseTileMap(const sf::Vector2i& mapSize) : mapSize(mapSize) { }

	const std::vector<int>& GetTileMap() const {
		return tileMap; 
	}

	const sf::Vector2i& GetMapSize() const {
		return mapSize;
	}

	const std::map<int, sf::String>& GetTypes() const {
		return typeMap;
	}

	protected:
	sf::Vector2i mapSize;
	std::vector<int> tileMap;
	std::map<int, sf::String> typeMap;

};

#endif // BASETILEMAP_H