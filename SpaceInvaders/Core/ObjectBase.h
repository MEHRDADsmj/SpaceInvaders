#pragma once

#include <vector>
#include <memory>

namespace Core
{
	template<class T>
	static std::shared_ptr<T> CreateObject();

class Component;

class ObjectBase
{
public:
	virtual ~ObjectBase();

	virtual void Update(double deltaTime);
	void AddComponent(Core::Component* comp);

private:
	std::vector<std::shared_ptr<Core::Component>> components;
};

}

template<class T>
std::shared_ptr<T> Core::CreateObject()
{
	if (std::is_base_of<Core::ObjectBase, T>::value == false) return nullptr;
	return std::make_shared<T>();
}
