#include "ObjectBase.h"
#include "Component.h"
#include <algorithm>
#include <type_traits>

Core::ObjectBase::ObjectBase() : pos { 0.0f, 0.0f }
{

}

Core::ObjectBase::~ObjectBase()
{
	std::for_each(components.begin(), components.end(), [](std::shared_ptr<Core::Component> it) -> void
		{
			it.reset();
		});
}

void Core::ObjectBase::Update(double deltaTime)
{
	std::for_each(components.begin(), components.end(), [](std::shared_ptr<Core::Component> it) -> void
		{
			it->Tick();
		});
}

void Core::ObjectBase::AddComponent(Core::Component* comp)
{
	std::shared_ptr<Core::Component> ptr {comp};
	components.push_back(ptr);
}

void Core::ObjectBase::SetPosition(float x, float y)
{
	this->pos = sf::Vector2f(x, y);
}

void Core::ObjectBase::SetPosition(sf::Vector2f position)
{
	this->pos = position;
}

sf::Vector2f Core::ObjectBase::GetPosition()
{
	return this->pos;
}
