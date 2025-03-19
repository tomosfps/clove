//
// Created by tom on 18/03/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SDL2/SDL.h>
#include <map>

class textureManager {
public:
	static textureManager* getInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new textureManager(); };

	bool loadTexture(const std::string& id, const std::string& filename);
	void removeTexture(const std::string& id);
	void cleanup();
	void draw(const std::string& id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(const std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	textureManager() {};
	static textureManager* s_Instance;
	std::map<std::string, SDL_Texture*> m_TextureMap{};

};

#endif //TEXTUREMANAGER_H
