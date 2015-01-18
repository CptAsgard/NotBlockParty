#ifndef OBJECT_H
#define OBJECT_H

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

/**
 * An object is anything in the world that does not require movement or an update function. e.g.: Grid, tiles
 * Therefore the world position and rotation can only be set once.
 * If you want an object that can move and update, see Entity.hpp
 */
class BaseObject {
	public:
	BaseObject( const sf::Vector2f& pos, float rot = 0 ); // set pos and rot

	sf::Vector2f GetPosition() const { return transform.getPosition(); }
	float GetRotation() const { return transform.getRotation();	}

	private:
	sf::Transformable transform;

	sf::Vector2f pos;
	float rot;

};

#endif //OBJECT_H