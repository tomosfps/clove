//
// Created by tom on 19/03/25.
//

#include "input/eventHandler.h"
#include "core/engine.h"

EventHandler* EventHandler::s_Instance = nullptr;

EventHandler::EventHandler() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void EventHandler::listen() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:	Engine::getInstance()->quit(); break;
			case SDL_KEYDOWN: keyDown(); break;
			case SDL_KEYUP: keyUp(); break;
		}
	}
}

bool EventHandler::getKeyDown(const SDL_Scancode key) {
	return (m_KeyStates[key] == 1);
}

void EventHandler::keyUp() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void EventHandler::keyDown() {
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}