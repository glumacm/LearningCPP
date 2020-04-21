#include "Button.hpp"

Button::Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor, string text)
{
	button_shape.setSize(buttonsize);
	button_shape.setFillColor(buttoncolor);
	button_shape.setPosition(buttonpos);
	Text tt;
	tt.setText(text);
	tt.setPosition(buttonpos);
	button_text = tt;
}
Button::Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor, Text buttontext)
{
	button_shape.setSize(buttonsize);
	button_shape.setPosition(buttonpos);
	button_shape.setFillColor(buttoncolor);
	button_text = buttontext;
}
Button::Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor)
{
	button_shape.setSize(buttonsize);
	button_shape.setPosition(buttonpos);
	button_shape.setFillColor(buttoncolor);
}

void Button::draw(sf::RenderWindow* window){
	//std::shared_ptr<sf::RenderWindow> window_pointer(window);
	window->draw(button_shape);
	button_text.draw(window);
}