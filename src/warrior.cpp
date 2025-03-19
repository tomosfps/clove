//
// Created by tom on 19/03/25.
//

#include "characters/warrior.h"
#include "graphics/textureManager.h"
#include <SDL2/SDL.h>

Warrior::Warrior(Properties* props): Character(props) {
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->setProps(props->m_TextureID, 0, 4, 100, SDL_FLIP_NONE);
}

void Warrior::draw() {
	m_Animation->draw(m_Transform->x, m_Transform->y, m_Width, m_Height);
}

void Warrior::update(const float deltaTime) {
	m_RigidBody->update(deltaTime + 0.2f);
	m_RigidBody->applyForceX(5.0f);

	m_Transform->translateX(m_RigidBody->getPosition().x);
	m_Transform->translateY(m_RigidBody->getPosition().y);

	m_Animation->update();
}

void Warrior::clean() {
	textureManager::getInstance()->cleanup();
}

