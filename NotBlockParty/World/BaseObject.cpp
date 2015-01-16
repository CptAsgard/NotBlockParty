#include "BaseObject.hpp"

BaseObject::BaseObject( const sf::Vector2f& pos, float rot ) : pos( pos ), rot( rot ) {
	transform.setPosition( pos );
	transform.setRotation( rot );
}