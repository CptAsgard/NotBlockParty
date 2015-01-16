#ifndef STATEMANAGER_H
#define STATEMANAGER_H 

#include <SFML\Window.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

#include "StateMessages.hpp"
#include "..\Messaging\MessageBus.hpp"

class GameState;

class StateManager {

	public:
	void Init( const sf::String& title, int32_t width, int32_t height );
	void CleanUp();

	void ChangeState( GameState *state );
	void PushState( GameState *state );
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return gameIsRunning; }
	void Quit() { gameIsRunning = false; }

	MessageBus Bus;

	private:
	std::vector<GameState*> states;

	bool gameIsRunning;

	sf::Window window;

	sf::Clock deltaClock;
};

#endif // STATEMANAGER_H