//
// Created by tom on 19/03/25.
//

#include "animation/animation.h"
#include "graphics/textureManager.h"

void Animation::update() {
	m_SpriteFrame = static_cast<int>((SDL_GetTicks() / m_AnimationSpeed) % m_FrameCount);
}

void Animation::draw(float x, float y, int spriteWidth, int spriteHeight) {
	textureManager::getInstance()->drawFrame(m_TextureID, static_cast<int>(x), static_cast<int>(y), spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::setProps(const std::string &textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip) {
	m_TextureID = textureID;
	m_SpriteRow = spriteRow;
	m_FrameCount = frameCount;
	m_AnimationSpeed = animationSpeed;
	m_Flip = flip;
}