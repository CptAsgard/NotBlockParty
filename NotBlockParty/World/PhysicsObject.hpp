#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML\Graphics.hpp>

class PhysicsObject {
	public:
	const sf::ConvexShape* getShape() {
		return &shape;
	}

	private:
	sf::ConvexShape shape;

};

#endif // PHYSICSOBJECT_H