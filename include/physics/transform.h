//
// Created by tom on 19/03/25.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "vector2D.h"

class Transform {
public:
	Transform(float x = 0, float y = 0 ): x(x), y(y) {};
	float x, y;

	void Log(const std::string& msg = "") {
		std::cout << msg << " (X, Y) = (" << x << ", " << y << ")" << std::endl;
	}

	inline void translateX(const float dx) {x += dx;}
	inline void translateY(const float dy) {y += dy;}
	inline void translate(const Vector2D v) {x += v.x; y += v.y;}
};

#endif //TRANSFORM_H
