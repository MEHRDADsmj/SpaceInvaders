#pragma once

#include <unordered_map>
#include <SFML/Window.hpp>

namespace Utility
{

class InputSystem
{
private:
	std::unordered_map<sf::Keyboard::Key, bool> keyStat;

public:
	void Tick();
};

}