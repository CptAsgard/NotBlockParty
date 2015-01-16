#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <unordered_map>
#include <stack>

#include "..\Engine\Messaging\MessageBus.hpp"

class Entity;
using EntityID = uint32_t;
#include "Entity.hpp"

using EntityPtr = std::shared_ptr<Entity>;
using WeakEntityPtr = std::weak_ptr<Entity>;

class EntityManager {
	public:
	EntityManager();

	WeakEntityPtr AddEntity( std::unique_ptr<Entity> entity );

	WeakEntityPtr FindEntity( EntityID id ) const;

	void RemoveEntity( const EntityID id );

	private:
	EntityID GetNextID();

	std::unordered_map<EntityID, EntityPtr> entities;

	std::stack<EntityID> freeIDs;
	EntityID nextID;

};

#endif // ENTITYMANAGER_H