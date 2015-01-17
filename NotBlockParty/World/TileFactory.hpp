#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include <map>
#include <string>
#include <functional>
#include <memory>

#include "..\Engine\Messaging\MessageBus.hpp"
#include "Objects.hpp"

using map_type = std::map<sf::String, std::function<Tile*()>>;

template<typename T> Tile* createT() {
	return new T;
}

class TileFactory {
	public:
	Tile* createInstance( sf::String const& type ) {
		map_type::iterator it = Instance()->getTypes()->find( type );
		if( it == Instance()->getTypes()->end() )
			return 0;
		return it->second();
	}

	static TileFactory* Instance() {
		if( tileFactory == nullptr )
			tileFactory = new TileFactory();

		return tileFactory;
	}

	map_type* getTypes() {
		if( !types ) {
			types = new map_type;
		}
		return types;
	}

	protected:
	TileFactory() {}

	private:
	static TileFactory* tileFactory;

	map_type* types;
};

TileFactory* TileFactory::tileFactory;

template<typename T>
struct DerivedRegister : TileFactory {
	public:
	DerivedRegister( sf::String const& s ) {
		TileFactory::Instance()->getTypes()->insert( std::make_pair( s, &createT<T> ) );
	}
};

#endif // TILEFACTORY_H