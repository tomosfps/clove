#include "core/engine.h"
#include "timer/timer.h"

int main() {
    Engine::getInstance()->init();

    while (Engine::getInstance()->isRunning()) {
        Engine::getInstance()->events();
        Engine::getInstance()->update();
        Engine::getInstance()->render();
        Timer::getInstance()->Tick();
    }

    Engine::getInstance()->cleanup();

    return 0;
}