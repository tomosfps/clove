//
// Created by tom on 18/03/25.
//

#include "graphics/textureManager.h"
#include "core/engine.h"

textureManager* textureManager::s_Instance = nullptr;

bool textureManager::loadTexture(const std::string& id, const std::string& filename) {
	SDL_Surface* surface = IMG_Load(filename.c_str());

	if (surface == nullptr) {
		SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), surface);

	if (texture == nullptr) {
		SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}

void textureManager::draw(const std::string& id, int x, int y, int width, int height, SDL_RendererFlip flip) {
	const SDL_Rect srcRect = { 0, 0, width, height };
	const SDL_Rect dstRect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void textureManager::drawFrame(const std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip) {
	SDL_Rect srcRect = { width * frame, height * row, width, height};
	SDL_Rect dstRect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}


void textureManager::removeTexture(const std::string& id) {
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void textureManager::cleanup() {
	std::map<std::string, SDL_Texture*>::iterator it;

	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); ++it) {
		SDL_DestroyTexture(it->second);
	}

	m_TextureMap.clear();

	SDL_Log("TextureManager cleaned up.");
}



