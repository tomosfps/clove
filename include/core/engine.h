//
// Created by tom on 18/03/25.
//../include/

#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine {
public:
	static Engine* getInstance() {
		return s_Instance = (s_Instance  != nullptr) ? s_Instance : new Engine();
	};

	bool init();
	bool cleanup();

	void quit();
	void update();
	void render();
	void events();
	inline bool isRunning() const { return m_IsRunning; };
	inline SDL_Renderer* getRenderer() const { return m_Renderer; };


  private:
    Engine() {};
    static Engine* s_Instance;
	SDL_Window* m_Window{};
	SDL_Renderer* m_Renderer{};
    bool m_IsRunning{};

};

#endif //ENGINE_H