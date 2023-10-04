#pragma once

#include <vector>
#include <memory>
#include <type_traits>

namespace Core
{
	template<class T>
	std::shared_ptr<T> CreateObject();

class Component;

class ObjectBase
{
public:
	virtual void Update(double deltaTime);
	void AddComponent(Core::Component* comp);

private:
	std::vector<std::shared_ptr<Core::Component>> components;
};

}
