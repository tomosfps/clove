//
// Created by tom on 19/03/25.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL2/SDL.h>

class EventHandler {
public:
	static EventHandler* getInstance() {
		return s_Instance = (s_Instance  != nullptr) ? s_Instance : new EventHandler();
	};

	void listen();
	bool getKeyDown(SDL_Scancode key);


private:
	EventHandler();
	void keyUp();
	void keyDown();

	const Uint8* m_KeyStates;

	static EventHandler* s_Instance;
};



#endif //EVENTHANDLER_H
