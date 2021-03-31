#pragma once
#include <SFML/Graphics.hpp>


class Button
{


	sf::RectangleShape rect;
	sf::Text Text;
public:
	Button(sf::Vector2i Position,std::string Text)
	{
		rect.setPosition(Position.x,Position.y);
		rect.setSize(sf::Vector2f(100,40));
		rect.setOutlineColor(sf::Color(74, 89, 57));
		rect.setFillColor(sf::Color(37, 37, 38));
		rect.setOutlineThickness(2);
	}

	void Render(sf::RenderWindow* window)
	{
		window->draw(rect);
	}

};
