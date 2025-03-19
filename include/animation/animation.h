//
// Created by tom on 19/03/25.
//

#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <SDL2/SDL_render.h>

class Animation {
public:
	Animation() {};

	void update();
	void draw(float x, float y, int spriteWidth, int spriteHeight);
	void setProps(const std::string &textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	int m_SpriteRow, m_SpriteFrame;
	int m_AnimationSpeed, m_FrameCount;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};



#endif //ANIMATION_H
