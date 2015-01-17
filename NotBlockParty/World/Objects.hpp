#ifndef OBJECTS_H
#define OBJECTS_H

#include "..\Engine\Messaging\MessageBus.hpp"

#include "BaseObject.hpp"
#include "GraphicsObject.hpp"
#include "PhysicsObject.hpp"

/**
 * TODO: replace Objects.hpp with a dynamic attribute system defined in data files
 */

class Tile : public BaseObject, public GraphicsObject, public PhysicsObject { 
	public:
	using BaseObject::BaseObject;

	const sf::Vector2f* GetGridPosition() const {
		return &gridPos;
	}

	private:
	sf::Vector2f gridPos;

};

class BlockTile : Tile {
	
};

#endif // OBJECTS_H