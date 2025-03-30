//
// Created by tom on 18/03/25.
//

#include "core/engine.h"
#include "graphics/textureManager.h"
#include "characters/warrior.h"
#include "input/eventHandler.h"
#include "timer/timer.h"

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

bool Engine::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("Failed to initialise SDL: %s", SDL_GetError());
    return false;
  }

  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
    SDL_Log("Failed to initialise SDL_Image: %s", IMG_GetError());
    return false;
  }

  m_Window = SDL_CreateWindow("Clove", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (m_Window == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (m_Renderer == nullptr) {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }

  textureManager::getInstance()->loadTexture("player", "/media/Downloads/Cute_Fantasy_Free/Player/Player.png");
  textureManager::getInstance()->loadTexture("player_run_x", "/media/Downloads/Cute_Fantasy_Free/Player/Player.png");
  textureManager::getInstance()->loadTexture("player_run_y", "/media/Downloads/Cute_Fantasy_Free/Player/Player.png");

  player = new Warrior(new Properties("player", 100, 200, 32, 32));

  return m_IsRunning = true;
};

bool Engine::cleanup() {
  textureManager::getInstance()->cleanup();

  SDL_DestroyWindow(m_Window);
  SDL_DestroyRenderer(m_Renderer);
  IMG_Quit();
  SDL_Quit();
  SDL_Log("Engine cleaned up.");

  return true;
};

void Engine::quit() {
  m_IsRunning = false;
};

void Engine::update() {
  float deltaTime = Timer::getInstance()->getDeltaTime();
  player->update(deltaTime);
};

void Engine::render() {
  SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, 255);
  SDL_RenderClear(m_Renderer);

  player->draw();
  SDL_RenderPresent(m_Renderer);
};

void Engine::events() {
  EventHandler::getInstance()->listen();
};