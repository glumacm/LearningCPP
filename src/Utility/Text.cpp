#include "Text.hpp"

Text::Text()
{
	//default values;
	text_size = 15;
	//path_to_font="";
	text_color = sf::Color::White;
	is_bold = false;
	text_position = {0,0};
	text_content = "Default text";
	createFont();
	setTextProps();
}
Text::Text(int textsize,string textcontent, string pathtofont, sf::Color textcolor, bool isbold, sf::Vector2f textposition)
{
	//text_font.loadFromFile(pathtofont);//absolute path
	//txt.setFont(text_font);
	//txt.setCharacterSize(textsize);
	text_content = textcontent;
	text_color = textcolor;
	text_size = textsize;
	is_bold = isbold;
	text_position = textposition;
	path_to_font = pathtofont;
	createFont();
	setTextProps();
}

bool Text::setFont(string pathtofont)
{
	try{
		path_to_font = pathtofont;
		createFont();
		setTextProps();
		return true;
	}catch(exception e){
		return false;
	}
}
void Text::createFont(){
	if(path_to_font=="")
	{
		return;
	}
	text_font = new sf::Font();
	text_font->loadFromFile(path_to_font);
	txt.setFont(*text_font);
}

void Text::setTextProps()
{
	txt.setString(text_content);
	txt.setCharacterSize(text_size);
	txt.setPosition(text_position);
	txt.setFillColor(text_color);
}
