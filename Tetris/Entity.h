#pragma once
#include <SFML/Graphics.hpp>
class Entity : public virtual sf::Drawable
{
public:
	virtual void handleEvent(sf::Event, sf::Window) = 0;
};

