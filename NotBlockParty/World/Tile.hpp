#ifndef TILE_H
#define TILE_H

#include "BaseObject.hpp"
#include "GraphicsObject.h"

/**
 * Currently Tile.hpp serves no other function than binding object data together.
 * It'd be much better to replace this with a dynamic attribute system defined in data files
 */
class Tile : public BaseObject, GraphicsObject {

};

#endif // TILE_H