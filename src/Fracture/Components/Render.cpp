#include "Render.h"
#include "../Components/Transform2D.h"

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	states.transform.combine(mTransform->getTransform());
	target.draw(*todraw, states);
}

void Render::Start()
{
	mTransform = Get<Transform2D>();
}

void Render::Awake()
{

}


