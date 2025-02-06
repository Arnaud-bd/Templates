#include "Render.h"
#include "../Components/Transform2D.h"

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	if (transform)
	{
		states.transform.combine(transform->getTransform());
	}
	target.draw(*todraw, states);
}

void Render::Start()
{
	transform = Get<Transform2D>();
}

void Render::Awake()
{

}


