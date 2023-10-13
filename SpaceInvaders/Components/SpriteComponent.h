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

private:
	std::shared_ptr<sf::RenderWindow> window;
};