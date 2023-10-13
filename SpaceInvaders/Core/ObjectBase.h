#pragma once

#include <vector>
#include <memory>
#include <SFML\System\Vector2.hpp>

namespace Core
{
	template<class T>
	static std::shared_ptr<T> CreateObject();

class Component;

class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase();

	virtual void Update(double deltaTime);
	void AddComponent(Core::Component* comp);

	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();

private:
	std::vector<std::shared_ptr<Core::Component>> components;
	sf::Vector2f pos;
};

}

template<class T>
std::shared_ptr<T> Core::CreateObject()
{
	if (std::is_base_of<Core::ObjectBase, T>::value == false) return nullptr;
	return std::make_shared<T>();
}
