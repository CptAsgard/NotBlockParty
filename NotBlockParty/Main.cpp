#include <SFML\Graphics.hpp>

#include "Game\State\StateManager.hpp"
#include "Game\State\PlayState.hpp"

#include <Thor\Resources.hpp>
#include <Thor\Particles.hpp>

int32_t main( int32_t argc, char **argv ) {
	StateManager game;

	game.Init( "Not Block Party", 1024, 768 );

	game.ChangeState( PlayState::Instance() );

	while( game.Running() ) {
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.CleanUp();

	return 0;
}