//
// Created by tom on 20/03/25.
//

#include "timer/timer.h"
#include <SDL2/SDL.h>

Timer* Timer::s_Instance = nullptr;

void Timer::Tick() {
	m_DeltaTime = (SDL_GetTicks() - m_LastFrame) * (TARGET_FPS / 1000.0f);

	if (m_DeltaTime > TARGET_DELTATIME) {
		m_DeltaTime = TARGET_DELTATIME;
	}

	m_LastFrame = SDL_GetTicks();
}

