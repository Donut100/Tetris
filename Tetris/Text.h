#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class MyTest: public sf::Text, public Entity
{
public:
	MyTest(const sf::String &string, const sf::Font &font, unsigned int characterSize=30, float x=0, float y=0);
	void draw(sf::RenderTarget& target, sf::RenderStates states);
	void handleEvent(sf::Event e, sf::Window window);
};

