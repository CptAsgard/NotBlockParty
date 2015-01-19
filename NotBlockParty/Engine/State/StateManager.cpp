#include "GameState.hpp"
#include "StateManager.hpp"

StateManager::StateManager() : messageBus( std::make_unique<MessageBus>() ) {

}

/**
 * Init creates the window, and starts the game.
 */
void StateManager::Init( const sf::String& title, int32_t width, int32_t height ) {
	// Create the window
	window.create( sf::VideoMode( width, height ), title );
	window.setVerticalSyncEnabled( true );

	graphicsMan = std::make_unique<GraphicsManager>();

	gameIsRunning = true;
}

/**
 * CleanUp should be called when the game has to completely halt execution.
 * NOTE: Will be called when the game loop exits. If you want to stop the game, call Quit().
 */
void StateManager::CleanUp() {
	for( uint8_t i = 0; i < states.size(); i++ ) {
		PopState();
	}

	// delete window
	window.close();
}


/**
 * Will clean up the current state, and push the given state to the top of the stack, and Init() it.
 * ChangeState should be used when the state of the previous state doesn't matter anymore.
 */
void StateManager::ChangeState( GameState* state ) {
	if( !states.empty() ) {
		states.back()->CleanUp();
		states.pop_back();
	}

	states.push_back( state );
	states.back()->Init( this );
}

/**
 * Will pause the current state, and push the given state to the top of the stack, and Init() it.
 * PushState should be used when you only want to temporarily halt a state, and come back to it later.
 */
void StateManager::PushState( GameState* state ) {
	if( !states.empty() ) {
		states.back()->Pause();
	}

	states.push_back( state );
	states.back()->Init( this );
}

/**
 * Will clean up the current state, and go back to the previous state on the stack.
 * Use this to revert to the old state.
 */
void StateManager::PopState() {
	if( !states.empty() ) {
		states.back()->CleanUp();
		states.pop_back();
	}

	if( !states.empty() ) {
		states.back()->Resume();
	}
}


/**
 * Will let the current state handle the events.
 */
void StateManager::HandleEvents() {
	if( window.isOpen() ) {
		sf::Event event;
		while( window.pollEvent( event ) ) {

			states.back()->HandleEvents( event );

			// Close window requested
			if( event.type == sf::Event::Closed ) {
				Quit();
			}
		}
	}
}

/**
 * Will let the current state update.
 */
void StateManager::Update() {
	messageBus->Send( FrameMessage{ deltaClock.restart().asSeconds() } );
}

/**
 * Will let the current state draw.
 */
void StateManager::Draw() {
	// clear

	states.back()->Draw( this );

	// swap buffers
}