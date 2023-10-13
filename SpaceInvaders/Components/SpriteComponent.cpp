#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(std::shared_ptr<sf::RenderWindow> window)
{
	this->window = window;
	texture = std::make_shared<sf::Texture>();
	LoadTexture("mario.png");
	sprite = std::make_shared<sf::Sprite>();
	sprite->setTexture(*(texture.get()));
	sprite->setPosition(300.f, 300.f);
	sprite->setScale(.1f, .1f);
}

SpriteComponent::~SpriteComponent()
{
	
}

void SpriteComponent::Tick()
{
	window->draw(*(sprite.get()));
}

void SpriteComponent::LoadTexture(std::string path)
{
	texture->loadFromFile("D:\\Projects\\CPP\\SpaceInvaders\\SpaceInvaders\\Components\\mario.png");
}
