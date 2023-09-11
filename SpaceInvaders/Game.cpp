#include "Game.h"
#include <iostream>

Game::Game() : deltaTime { 0.f }
{
	
}

Game::~Game()
{

}

void Game::Start()
{

}

void Game::Update(float frameTime)
{
	std::cout << frameTime << std::endl;
	deltaTime = frameTime;
}

void Game::Close()
{

}
