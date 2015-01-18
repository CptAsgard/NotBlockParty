#ifndef STATEMANAGER_H
#define STATEMANAGER_H 

#include <SFML\Window.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

#include "..\Messaging\MessageBus.hpp"
#include "StateMessages.hpp"

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

	private:
	std::vector<GameState*> states;

	std::unique_ptr<MessageBus> messageBus;

	bool gameIsRunning;

	sf::Window window;
	sf::Clock deltaClock;

};

#endif // STATEMANAGER_H