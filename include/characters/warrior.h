//
// Created by tom on 19/03/25.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include "animation/animation.h"
#include "physics/rigidBody.h"

class Warrior : public Character{
public:
	Warrior(Properties* props);

	virtual void draw();
	virtual void update(float deltaTime);
	virtual void clean();

private:
	Animation* m_Animation;
	RigidBody* m_RigidBody;
};



#endif //WARRIOR_H
