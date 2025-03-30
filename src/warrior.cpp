//
// Created by tom on 19/03/25.
//

#include "characters/warrior.h"
#include "graphics/textureManager.h"
#include <SDL2/SDL.h>

#include "input/eventHandler.h"

Warrior::Warrior(Properties* props): Character(props) {
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->setProps(props->m_TextureID, 0, 4, 100, SDL_FLIP_NONE);
}

void Warrior::draw() {
	m_Animation->draw(m_Transform->x, m_Transform->y, m_Width, m_Height);
}

void Warrior::update(const float deltaTime) {
	m_Animation->setProps("player", 0, 4, 100, SDL_FLIP_NONE);
	m_RigidBody->unsetForce();

	if (EventHandler::getInstance()->getKeyDown(SDL_SCANCODE_A)) {
		m_RigidBody->applyForceX(-5.0f);
		m_Animation->setProps("player_run_x", 4, 4, 100, SDL_FLIP_HORIZONTAL);
	}

	if (EventHandler::getInstance()->getKeyDown(SDL_SCANCODE_D)) {
		m_RigidBody->applyForceX(5.0f);
		m_Animation->setProps("player_run_x", 4, 4, 100, SDL_FLIP_NONE);
	}

	if (EventHandler::getInstance()->getKeyDown(SDL_SCANCODE_W)) {
		m_RigidBody->applyForceY(-5.0f);
		m_Animation->setProps("player_run_y", 5, 4, 100, SDL_FLIP_HORIZONTAL);
	}

	if (EventHandler::getInstance()->getKeyDown(SDL_SCANCODE_S)) {
		m_RigidBody->applyForceY(5.0f);
		m_Animation->setProps("player_run_y", 3, 4, 100, SDL_FLIP_NONE);
	}

	SDL_Log("%f", deltaTime);
	m_RigidBody->update(deltaTime);
	m_Transform->translateX(m_RigidBody->getPosition().x);
	//m_Transform->translateY(m_RigidBody->getPosition().y);

	m_Animation->update();
}

void Warrior::clean() {
	textureManager::getInstance()->cleanup();
}

