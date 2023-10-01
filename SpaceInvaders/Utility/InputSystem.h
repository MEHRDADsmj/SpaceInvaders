#pragma once

#include <unordered_map>
#include <SFML/Window.hpp>
#include <functional>

namespace Utility
{

class InputSystem
{
private:
	std::unordered_map<sf::Keyboard::Key, std::vector<std::function<void(void)>>> keyAction;

public:
	void Tick();
	void BindAction(sf::Keyboard::Key key, std::function<void(void)> func);
	void UnbindAction(sf::Keyboard::Key key, std::function<void(void)> func);
};

}