#ifndef STATEMESSAGES_H
#define STATEMESSAGES_H

#include <memory>

#include "StateManager.hpp"

class StateManager;

struct FrameMessage {
	float deltaTime;
	std::weak_ptr<StateManager> manager;
};

#endif STATEMESSAGES_H