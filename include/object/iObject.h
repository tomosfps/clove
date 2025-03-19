//
// Created by tom on 19/03/25.
//

#ifndef IOBJECT_H
#define IOBJECT_H

class IObject {
public:
	virtual void draw() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void clean() = 0;
};

#endif //IOBJECT_H
