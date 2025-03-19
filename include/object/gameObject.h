//
// Created by tom on 19/03/25.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL_render.h>
#include "iObject.h"
#include "physics/transform.h"

struct Properties {
public:
	Properties(const std::string& textureID, const float x, const float y, const int w, const int h, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		this->x = x;
		this->y = y;
		this->m_TextureID = textureID;
		this->m_Width = w;
		this->m_Height = h;
		this->m_Flip = flip;
	}

public:
	std::string m_TextureID;
	int m_Width, m_Height;
	float x, y;
	SDL_RendererFlip m_Flip;
};

class GameObject : IObject {
public:
	GameObject(const Properties* props): m_Width(props->m_Width),
	m_Height(props->m_Height), m_TextureID(props->m_TextureID), m_Flip(props->m_Flip) {
		m_Transform = new Transform(props->x, props->y);
	};

	virtual void draw() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void clean() = 0;
protected:
	Transform* m_Transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};

#endif //GAMEOBJECT_H
