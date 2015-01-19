#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.hpp"

#include "..\..\World\Entity\EntityManager.hpp"
#include "..\..\World\Maps\TileMapRenderer.hpp"
#include "..\..\World\Maps\DEBUG_Level1TileMap.hpp"

class PlayState : public GameState {

	public:
	void Init( StateManager *game );
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents( sf::Event const& event );
	void Update( StateManager *game, float deltaTime );
	void Draw( StateManager *game );

	static PlayState* Instance() {
		return &_playState;
	}

	protected:
	PlayState();

	private:
	static PlayState _playState;

	std::unique_ptr<TileMapRenderer> tileMapRenderer;
	std::unique_ptr<BaseTileMap> currentMap;

};
#endif // PLAYSTATE_H










