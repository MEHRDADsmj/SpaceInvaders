#pragma once

namespace Core
{

class Component
{
public:
	virtual ~Component() = default;
	virtual void Tick() = 0;
};

}
