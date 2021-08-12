#include "Text.h"

MyTest::MyTest(const sf::String & string, const sf::Font & font, unsigned int characterSize, float x, float y) : Text(string, font, characterSize)
{
	this->setPosition(x, y);
}

void MyTest::draw(sf::RenderTarget & target, sf::RenderStates states)
{

}

void MyTest::handleEvent(sf::Event e, sf::Window window)
{
	if (e.type == sf::Event::MouseMoved)
	{
		sf::Vector2<float> mousePos(float(e.mouseMove.x), float(e.mouseMove.y));
		if (this->getGlobalBounds().contains(mousePos))
		{
			sf::Cursor c;
			if (c.loadFromSystem(sf::Cursor::Hand))
				window.setMouseCursor(c);
		}

	}
}
