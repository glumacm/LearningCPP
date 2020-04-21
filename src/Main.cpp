#include "Platform/Platform.hpp"
#include "Utility/utilityFunctions.hpp"
#include <memory>
//#include "Utility/Carddeck.hpp"
//#include "Utility/Button.hpp"
#include "Utility/Player/PlayerUiContainer.hpp"
//#include "Utility/Text.hpp"
#include <string>
#include <iostream>
#include <experimental/filesystem>
//#include <iostream>
//#include <string>
//#include <vector>


bool clickInRange(sf::Vector2f button_start_coordinates, sf::Vector2f button_size, sf::Vector2i mouse_pos );

/*
sf::RectangleShape createShapeOnPosWithSize(float height, float width, float x, float y ,sf::Texture*  shape_texture,std::string odjebi){
	sf::RectangleShape the_shape(sf::Vector2f{height,width});
	the_shape.setFillColor(sf::Color::Green);
	the_shape.setPosition(sf::Vector2f{x,y});
	sf::Texture b;
	b.loadFromFile(odjebi);
	*shape_texture = b;
	the_shape.setTexture(shape_texture);
	return the_shape;
}*/

namespace fs = std::experimental::filesystem;
std::vector<Card> mycards;
int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif


	/**
	 * 'Texture* tx' ---> pointer
	 * 'Texture& tx' ---> reference
	 */

	/**
	 * Pointer example:
	 *
	 * int x = 5;
	 * int y = 6;
	 * int *r ;
	 * &r = x;
	 * &r = y;
	 * VSSE SKUPAJ JE MALCE UFFF... NAMREC PRAVIJO DA NAJ BI POINTERJI VEDNO KAZALI NA NASLOV.
	 * A NATO VIDIS PRIMERE KO LAHKO SPREMENIS VSEBINO.... WHAT?...
	 *
	 */

	/*
		int x = 35;
		int y = 46;
		x   y
		+---+---+---+---+---+--
		| 35| 46|   |   |   | ...
		+---+---+---+---+---+--
		100 101 102 103 104  ...
		int *p = &x;
		int *q = &y;
		x   y   p   q
		+---+---+---+---+---+--
		| 35| 46|100|101|   | ...
		+---+---+---+---+---+--
		100 101 102 103 104  ...
		p = q;
		x   y   p   q
		+---+---+---+---+---+--
		| 35| 46|101|101|   | ...
		+---+---+---+---+---+--
		100 101 102 103 104  ...
		*p = 90;
		x   y   p   q
		+---+---+---+---+---+--
		| 35| 90|101|101|   | ...
		+---+---+---+---+---+--
		100 101 102 103 104  ...
	*/

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor

	/**
	 * Kruta resnica --> ce imoprtamo razred A, ki hkrati importa razred B. Potem tukaj ne smemo ...
	 * ponovno importat razred B!!!!!
	 */
	Carddeck mydeck(sf::Vector2f{0,0},"content/PNG/", 10);



	sf::CircleShape sff;
	sf::Vector2f card_size(40,80); //To je velikost kvadrata.



	/*
	BASIC EXAMPLE

	float initialX = 0;
	float initialY = 0;
	sf::RectangleShape card(sf::Vector2f{20,40});
	sf::Texture tt;
	tt.loadFromFile("/home/matjazglumac/Desktop/Programming/sfml-vscode-boilerplate/content/PNG/3H.png");
	card.setPosition(sf::Vector2f{0,0});
	card.setTexture(&tt);

	My custom stuff before OPP
	Card firstCard("content/PNG/2C.png",card_size,sf::Vector2f{initialX,initialY});
	mycards.push_back(firstCard);
	initialX = addStep(initialX,card_size.x);
	Card secondCard("content/PNG/3C.png",card_size,sf::Vector2f{initialX,initialY});
	mycards.push_back(secondCard);

	initialX =addStep(initialX,card_size.x);
	Card thirdCard("content/PNG/4C.png",card_size,sf::Vector2f{initialX,initialY});
	mycards.push_back(thirdCard);
	*/

	window.create(sf::VideoMode(640.0f * screenScalingFactor, 480.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());


	sf::Event event;

	/*
	//kako izpisati vse datoteke iz trenutnega direktorija.
	string absolutepath = fs::absolute("");
	std::cout << "To je pot: " + absolutepath << std::endl;
	std::cout << "[ ";
	for(const auto entry : fs::directory_iterator(absolutepath+"/./content/PNG")){
		std::cout <<"\"" + entry.path().filename().string().substr(0,entry.path().filename().string().size()-4) << "\", ";
	}
	std::cout << std::endl;
	*/
	Carddeck full_deck(sf::Vector2f{0,60},fs::absolute("").string()+"/content/PNG",10);
 	full_deck.setCardSize(card_size);
 	full_deck.createFullDeck();
	std::cout <<  "Full_deck score:" << full_deck.getDeckScore()<< std::endl;
	//std::cout <<  "Full_deck score after draw: " << full_deck.getDeckScore() << std::endl;

	Carddeck dealer (sf::Vector2f{0,40},fs::absolute("").string()+"/content/PNG",0);
	Carddeck player1(sf::Vector2f{0,60},fs::absolute("").string()+"/content/PNG",0);
	Card drawcard(fs::absolute("").string()+"/content/PNG/green_back.png",card_size,sf::Vector2f{0,140}, "");
	dealer.setCardSize(card_size);
	dealer.addCard(full_deck.drawCard());
	dealer.addCard(full_deck.drawCard());
	//std::cout <<  "Full_deck score after second draw: " << full_deck.getDeckScore() << std::endl;
	std::cout << "Dealer finished drawing! Dealer score: "<< dealer.getDeckScore()<<std::endl;

	//green_back.png --> to bo za pobrat karto!
	sf::Text textt;
	sf::Text blackjackgame;
	sf::Text drawcardtext;
	sf::Text winner;
	sf::Text loser;
	sf::Text gameover;
	sf::Font font;
	font.loadFromFile(fs::absolute("").string()+"/content/fonts/arial.ttf");
	float center_x = float(window.getSize().x/2)-(24*5);

	cout << "Before text creation \n";
	Text blackjacknew(24,"BLACK JACK",
	fs::absolute("").string()+"/content/fonts/arial.ttf",
	sf::Color::Green,true,sf::Vector2f{center_x,0});

	cout << "Before button creatio n\n";
	Button b1(sf::Vector2f{80,40},sf::Vector2f{20,50},
	sf::Color::Red,"Draw card");//Kasneje dodamo centering besedila

	Player p1;
	p1.setPlayerName("Player 1");
	PlayerUiContainer pp1(p1);
	pp1.setWindowReference(&window);

	textt.setFont(font);
	blackjackgame.setFont(font);
	drawcardtext.setFont(font);
	winner.setFont(font);
	loser.setFont(font);
	gameover.setFont(font);

	textt.setString("In my safe space.... my safe space.");

	textt.setFillColor(sf::Color::Red);
	textt.setCharacterSize(14);
	//textt.setPosition(sf::Vector2f{0,80});
	textt.setStyle(sf::Text::Bold);
	//Card n("",card_size,sf::Vector2f{0,0},"");
	//vector<Card> test {n};
	/*
	test.pop_back();
	std::cout << "What happens when we remove from vector non existing element from back \n";
	Card somenew = test.back();
	cout << somenew.printString() << endl;
	*/
	while (window.isOpen())
	{
		/*
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
    // left click...
}
// get global mouse position
sf::Vector2i position = sf::Mouse::getPosition();
*/



		while (window.pollEvent(event))
		{
			pp1.checkAndUpdate(&event);
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					//event.mouse
					//sf::Vector2i mouse_position{event.mouseMove.x, event.mouseMove.y};
					/*sf::Vector2i mouse_position{event.mouseButton.x, event.mouseButton.y};
					//sf::Vector2i mouse_position = sf::Mouse::getPosition();
					std::cout << "Mouse pressed at: " << mouse_position.x << " and , " << mouse_position.y <<std::endl;
					std::cout << "Draw button clicked: " << clickInRange(drawcard.getCard().getPosition(), drawcard.getCard().getSize(), mouse_position) << std::endl;
					std::cout << "Button size width: " << drawcard.getCard().getSize().x << " , button size height: "<< drawcard.getCard().getSize().y<<std::endl;
					std::cout << "Button position x: " << drawcard.getCard().getPosition().x << " , button position y: "<< drawcard.getCard().getPosition().y<<std::endl;

					dealer.addCard(full_deck.drawCard());
					std::cout << "Delaer has new score of:  " << dealer.getDeckScore() << std::endl;
					*/
				}
			}
		}

		window.clear();
		//window.draw(textt);
		//window.draw(blackjacknew.getTxt());
		//blackjacknew.draw(&window);

		pp1.draw();


		//b1.draw(&window);
		window.draw(drawcard.getCard());
		for(Card my_card : dealer.getDeck()){
			window.draw(my_card.getCard());
		}
		window.display();
	}

	return 0;
}

//button_size.x -- width
//button_size.y -- height
bool clickInRange(sf::Vector2f button_start_coordinates, sf::Vector2f button_size, sf::Vector2i mouse_pos ){
	if(
		(mouse_pos.x >= button_start_coordinates.x && mouse_pos.x <= button_start_coordinates.x + button_size.x ) &&
		(mouse_pos.y >= button_start_coordinates.y && mouse_pos.y <= button_start_coordinates.y +button_size.y)
	){
		return true;
	}
	return false;
}
