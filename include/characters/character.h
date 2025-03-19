//
// Created by tom on 19/03/25.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "object/gameObject.h"
#include <string>

class Character : public GameObject {
public:
	Character(Properties* props): GameObject(props) {};
	virtual void draw() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void clean() = 0;

protected:
	std::string m_Name;
};

#endif //CHARACTER_H
