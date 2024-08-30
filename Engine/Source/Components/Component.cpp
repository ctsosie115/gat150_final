#include "Component.h"

std::unique_ptr<Object> Component::Clone()
{
	return std::unique_ptr<Object>();
}

void Component::Read(const json_t& value)
{
}

void Component::Write(json_t& value)
{
}

