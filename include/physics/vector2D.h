//
// Created by tom on 19/03/25.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <string>

class Vector2D {
public:
	float x, y;
	Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

	inline Vector2D operator+(const Vector2D &other) const {
		return {x + other.x, y + other.y};
	}

	inline Vector2D operator-(const Vector2D &other) const {
		return {x - other.x, y - other.y};
	}

	inline Vector2D operator*(const float scalar) const {
		return {x * scalar, y * scalar};
	}

	inline Vector2D operator/(const float scalar) const {
		return {x / scalar, y / scalar};
	}

	void Log(const std::string& msg = "") {
		std::cout << msg << " (X, Y) = (" << x << ", " << y << ")" << std::endl;
	}

private:

};

#endif //VECTOR2D_H

