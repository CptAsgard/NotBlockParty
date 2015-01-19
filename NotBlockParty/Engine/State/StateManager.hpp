#ifndef STATEMANAGER_H
#define STATEMANAGER_H 

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>

#include "..\Messaging\MessageBus.hpp"
#include "StateMessages.hpp"
#include "..\Rendering\GraphicsManager.hpp"

class GameState;
class GraphicsManager;

class StateManager {

	public:
	StateManager();

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

	MessageBus* GetMessageBus() { return messageBus.get(); }

	sf::RenderWindow window;

	private:
	std::vector<GameState*> states;

	std::unique_ptr<MessageBus> messageBus;
	std::unique_ptr<GraphicsManager> graphicsMan;

	bool gameIsRunning;

	sf::Clock deltaClock;

};

#endif // STATEMANAGER_H