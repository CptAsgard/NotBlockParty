#include "PlayState.hpp"

PlayState PlayState::_playState;

PlayState::PlayState() {

}

void PlayState::Init( StateManager* game ) {

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

}