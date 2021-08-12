#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Text.h"

int main()
{
	std::vector<Entity*> shapes;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris");
	sf::Vector2u windowSize = window.getSize();
	sf::Event event;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	MyTest text("click me", font, 50, windowSize.x / 2.0f, 10.0f);
	text.setOutlineColor(sf::Color::Cyan);
	text.setOutlineThickness(1);

	MyTest reset("reset", font, 35, windowSize.x / 2.0f, 550.0f);
	reset.setFillColor(sf::Color::Red);

	shapes.push_back(&text);
	shapes.push_back(&reset);


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			std::cout << event.type << std::endl;
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				sf::Vector2<float> v(float(event.mouseMove.x), float(event.mouseMove.y));
				if (text.getGlobalBounds().contains(v) || reset.getGlobalBounds().contains(v))
				{
					sf::Cursor c;
					if (c.loadFromSystem(sf::Cursor::Hand))
						window.setMouseCursor(c);
				}
				else
				{
					sf::Cursor c;
					if (c.loadFromSystem(sf::Cursor::Arrow))
						window.setMouseCursor(c);
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2<float> v(float(event.mouseButton.x), float(event.mouseButton.y));
				if (text.getGlobalBounds().contains(v))
				{
					text.setString("Clicked!");
				}
				else if (reset.getGlobalBounds().contains(v))
				{
					text.setString("click me");
				}
			}
		}
		window.clear();

		for (Entity* shape : shapes)
		{
			sf::Drawable* d = (sf::Drawable*)shape;
			window.draw(*d);
		}

		window.display();
	}
	return 0;
}