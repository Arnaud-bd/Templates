#include "Render.h"
#include "../Components/Transform2D.h"

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	//states.transform = Get<Transform2D>()->getTransform();
	target.draw(*todraw, states);
}

void Render::Start()
{
}

void Render::Awake()
{

}


