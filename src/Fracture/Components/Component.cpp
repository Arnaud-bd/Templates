
#include "Component.hpp"

Component::Component()
{
}

uint64_t Component::GetID()
{
    return m_ID;
}

void Component::SetID(uint64_t _ID)
{
    m_ID = _ID;
}
