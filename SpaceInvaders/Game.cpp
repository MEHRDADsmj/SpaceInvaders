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

void Game::Update(double frameTime)
{
	std::cout << frameTime << std::endl;
	deltaTime = frameTime;
}

void Game::Close()
{

}
