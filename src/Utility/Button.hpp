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
		Button(){};
		//void draw(sf::RenderWindow* window){button_text.draw(window);window->draw(button_shape);}
		sf::Vector2f getButtonPosition(){return button_shape.getPosition();}
		sf::Vector2f getButtonSize(){return button_shape.getSize();}
		string getButtonName(){return button_text.getTxt().getString();}
		void draw(sf::RenderWindow* window);
};