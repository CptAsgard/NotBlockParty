#include "PlayState.hpp"

PlayState PlayState::_playState;

PlayState::PlayState() {
	
}

void PlayState::Init( StateManager* game ) {
	currentMap = std::make_unique<DEBUG_Level1TileMap>();
	tileMapRenderer = std::make_unique<TileMapRenderer>(game);
	tileMapRenderer->Load( *currentMap );
}

void PlayState::CleanUp() {

}

void PlayState::Pause() {

}

void PlayState::Resume() {

}

void PlayState::HandleEvents( sf::Event const& event ) {

}

void PlayState::Update( StateManager* game, float deltaTime ) {
	std::cout << deltaTime << std::endl;
}

void PlayState::Draw( StateManager* game ) {
	game->window.clear();

	//game->window.draw( *tileMapRenderer );
	game->GetMessageBus()->Send( DrawMessage{ &game->window } );

	game->window.display();
}