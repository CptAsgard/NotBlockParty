#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.hpp"

class PlayState : public GameState {

	public:
	void Init( StateManager *game );
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents( sf::Event const& event );
	void Update( StateManager *game, float deltaTime );
	void Draw( StateManager *game );

	void HandleMessage( const FrameMessage& mess );

	static PlayState* Instance() {
		return &_playState;
	}

	protected:
	PlayState();

	private:
	static PlayState _playState;

};
#endif // PLAYSTATE_H










