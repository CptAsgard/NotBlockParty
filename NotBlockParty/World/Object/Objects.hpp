#ifndef OBJECTS_H
#define OBJECTS_H

#include "BaseObject.hpp"
#include "GraphicsObject.hpp"
#include "PhysicsObject.hpp"

/**
 * TODO: replace Objects.hpp with a dynamic attribute system defined in data files
 */

class Tile : public BaseObject, public GraphicsObject, public PhysicsObject { 
	public:
	Tile(const sf::Vector2f& gridPos) : BaseObject(gridPos) { }

	const sf::Vector2f* GetGridPosition() const {
		return &gridPos;
	}

	private:
	sf::Vector2f gridPos;

};

class BlockTile : Tile {

	private:
	static DerivedRegister<BlockTile> reg;
};
DerivedRegister<BlockTile> BlockTile::reg( "Block" );


#endif // OBJECTS_H