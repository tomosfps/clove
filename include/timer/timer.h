//
// Created by tom on 20/03/25.
//

#ifndef TIMER_H
#define TIMER_H

constexpr int TARGET_FPS = 60;
constexpr float TARGET_DELTATIME = 1.5f;

class Timer {
public:
	void Tick();
	inline float getDeltaTime() const { return m_DeltaTime; }
	inline static Timer* getInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer(); }

private:
	Timer() {};
	static Timer* s_Instance;
	float m_DeltaTime;
	float m_LastFrame;
};



#endif //TIMER_H
