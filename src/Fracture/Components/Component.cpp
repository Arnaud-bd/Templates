#include "Component.hpp"

Component::Component()
{
}

uint64_t Component::GetID() const
{
    return m_ID;
}

void Component::ToDestroy()
{
    m_toDestroy = true;
}

bool Component::IsDestroy()
{
    return m_toDestroy;
}

void Component::SetID(uint64_t _ID)
{
    m_ID = _ID;
}
