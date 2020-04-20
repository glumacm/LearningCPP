#include "Card.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <experimental/filesystem>
using namespace std;
class Carddeck
{
private:
	/* data */
	//declaration with empty constructors
	vector<Card> my_cards;
	sf::Vector2f deck_position;
	string path_to_deck_textures;
	int size_of_deck; //equals to number of textures in path_to_deck_textures;

	// initialized data
	int deck_score = 0;
	//Uporabljam 'const' da se naucim uporabljati ta konstrukt, da zascitim nespreminjajoce podatke.
	sf::Vector2f card_size {20,40};
	vector<string> textures_list{  "3H", "6H", "5D", "2C",
	 "KC", "8D", "10S", "QC", "2S", "9D", "JH",
	 "2D", "5S", "8S", "4H",
	  "AS", "8C", "7S", "5H", "3S",
	   "6C", "KH", "2H", "7C",
	    "5C", "JS", "6D", "JD",
		"AC", "7H",
		 "7D", "3C", "JC", "QS", "4S", "4D",
	 "10D", "4C", "KD", "9S", "QD", "AH",
	 "9H", "10H", "AD", "9C", "10C", "KS", "3D", "6S", "QH", "8H"};
	 string texture_extension = ".png";
	 int cards_offset = 10;
	 int black_jack_perfection = 21;


public:
	Carddeck(/* args */sf::Vector2f starting_position, string relative_path_to_images, int deck_size);
	~Carddeck();
	void addCard (Card new_card);
	bool createFullDeck();
	int randomizeShuffle(int i);
	vector<Card> getDeck(){return my_cards;}
	int getDeckScore() {return deck_score;}
	int calculateDeckValue();//should be deprecated
	void setCardSize(sf::Vector2f new_card_size);
	void addCardValueToDeck(Card thecard);
	Card drawCard();
	void addStepOnCoordinates(sf::Vector2f* pos, sf::Vector2f* size, float offset);
};

