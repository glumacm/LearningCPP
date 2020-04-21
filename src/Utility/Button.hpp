#include "Text.hpp"

class Button
{
	private:
		Text button_text;
		sf::RectangleShape button_shape;

	public:
		Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor, string text);
		Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor, Text buttontext);
		Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor);
		//void draw(sf::RenderWindow* window){button_text.draw(window);window->draw(button_shape);}
		void draw(sf::RenderWindow* window);
};