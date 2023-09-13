#include "InputSystem.h"
#include <iostream>

using namespace Utility;

void InputSystem::Tick()
{
	for (short keyCode = 0; keyCode < sf::Keyboard::KeyCount; ++keyCode)
	{
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keyCode))
		{
			std::for_each (keyAction[(sf::Keyboard::Key)keyCode].begin(), keyAction[(sf::Keyboard::Key)keyCode].end(), 
				[](const std::function<void(void)>& func) -> void 
				{
					 func();
				});
		}
	}
}

void InputSystem::BindAction(sf::Keyboard::Key key, std::function<void(void)>&& func)
{
	keyAction[key].push_back(func);
}

void InputSystem::UnbindAction(sf::Keyboard::Key key, std::function<void(void)>&& func)
{
	// TODO: make it happen. Probably write a delegate system
}
