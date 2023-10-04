#include "ObjectBase.h"
#include "Component.h"
#include <algorithm>

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

template<class T>
std::shared_ptr<T> Core::CreateObject()
{
	if (std::is_base_of_v<Core::ObjectBase, T> == false) return nullptr;
	return std::make_shared<T>();
}
