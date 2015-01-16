#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>

#include "EntityManager.hpp"

class Entity : sf::Transformable {
	public:
	EntityID GetID() const;
	void Entity::SetID( EntityID id );

	private:
	EntityID id;
	
};

#endif //ENTITY_H