#include "InputSystem.h"
#include <iostream>

using namespace Utility;

void InputSystem::Tick()
{
	for (short keyCode = 0; keyCode < sf::Keyboard::KeyCount; ++keyCode)
	{
		keyStat[(sf::Keyboard::Key)keyCode] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keyCode);
	}

	std::for_each (keyStat.begin(), keyStat.end(), [](const std::pair<sf::Keyboard::Key, bool> pair) -> void 
	{
		if (!pair.second) return;
		std::cout << pair.first << std::endl;
	});
}