#pragma once
#include "../Core/Component.h"
#include "SFML\Graphics.hpp"
#include <memory>

using namespace Core;

class SpriteComponent : public Component
{
public:
	SpriteComponent(std::shared_ptr<sf::RenderWindow> window);
	virtual ~SpriteComponent() override;
	virtual void Tick() override;
	void LoadTexture(std::string path);

private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Texture> texture;
	std::shared_ptr<sf::Sprite> sprite;
};