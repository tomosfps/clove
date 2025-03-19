//
// Created by tom on 19/03/25.
//

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "vector2D.h"

#define UNI_MASS 1.0f
#define UNI_GRAVITY 9.8f

class RigidBody {
public:
	RigidBody(): m_Mass(UNI_MASS), m_Gravity(UNI_GRAVITY) {};

	// Setter For Gravity & Mass
	inline void setMass(float mass) { m_Mass = mass; }
	inline void setGravity(float gravity) { m_Gravity = gravity; }

	// Setter For Force
	inline void applyForce(const Vector2D& force) { m_Force = force; }
	inline void applyForceX(const float fx) { m_Force.x = fx; }
	inline void applyForceY(const float fy) { m_Force.y = fy; }
	inline void unsetForce() { m_Force = Vector2D(0.0f, 0.0f); }

	// Setter For Friction
	inline void applyFriction(const Vector2D& friction) { m_Friction = friction; }
	inline void unsetFriction() { m_Friction = Vector2D(0.0f, 0.0f); }

	inline float getMass() const { return m_Mass; }
	inline Vector2D getPosition() const { return m_Position; }
	inline Vector2D getVelocity() const { return m_Velocity; }
	inline Vector2D getAcceleration() const { return m_Acceleration; }

	// Update Method
	void update(float deltaTime) {
		m_Acceleration.x = (m_Force.x - m_Friction.x) / m_Mass;
		m_Acceleration.y = m_Gravity + m_Force.y / m_Mass;
		m_Velocity = m_Acceleration * deltaTime;
		m_Position = m_Velocity * deltaTime;
	}

private:
	float m_Mass;
	float m_Gravity;

	Vector2D m_Force;
	Vector2D m_Friction;

	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Acceleration;
};

#endif //RIGIDBODY_H
