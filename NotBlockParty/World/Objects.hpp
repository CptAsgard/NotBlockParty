#ifndef OBJECTS_H
#define OBJECTS_H

#include "BaseObject.hpp"
#include "GraphicsObject.hpp"
#include "PhysicsObject.hpp"

/**
 * Currently Objects.hpp serves no other function than binding object data together.
 * It'd be much better to replace this with a dynamic attribute system defined in data files
 */

class Tile : public BaseObject, public GraphicsObject, public PhysicsObject { };

#endif // OBJECTS_H