#ifndef OBJECTMESSAGES_H
#define OBJECTMESSAGES_H

#include <SFML\System.hpp>

struct RegisterTileType {
	sf::String UID;
};

struct CreateTileRequested {
	sf::String UID;
};

#endif // OBJECTMESSAGES_H