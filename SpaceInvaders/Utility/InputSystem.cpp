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

void InputSystem::BindAction(sf::Keyboard::Key key, std::function<void(void)> func)
{
	keyAction[key].push_back(func);
}

void InputSystem::UnbindAction(sf::Keyboard::Key key, std::function<void(void)> func)
{
	// TODO: make it happen. Probably write a delegate system
	auto& actions = keyAction[key];
	auto it = std::find_if(actions.begin(), actions.end(), [=](std::function<void(void)> func2) -> bool
		{
			return func.target_type() == func2.target_type();
		});
	if (it == actions.end()) return;
	actions.erase(it);
}
