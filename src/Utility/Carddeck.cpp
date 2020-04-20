#include "Carddeck.hpp"
#include <iostream>
#include <experimental/filesystem>


namespace fs = std::experimental::filesystem;
Carddeck::Carddeck(/* args */sf::Vector2f starting_position, string relative_path_to_images, int deck_size)
{
	deck_position = starting_position;
	size_of_deck = deck_size;
	path_to_deck_textures = relative_path_to_images;
}

Carddeck::~Carddeck()
{
	path_to_deck_textures = "";
	deck_position = {0,0};
}

bool Carddeck::createFullDeck(){
	if(path_to_deck_textures == "" || (&path_to_deck_textures==NULL)){
		return false;
	}
	int current_deck = 0;
	sf::Vector2f current_coordinates = deck_position;
	for(string card_texture : textures_list){
		//std::cout << "Full size: " << size_of_deck << " current size: " << current_deck << std::endl;
		if(current_deck == size_of_deck){
			break;
		}
		//pathtotexture
		//size
		//coordinates
		string full_path_to_card = path_to_deck_textures+"/"+card_texture+texture_extension;
		if(fs::is_regular_file(full_path_to_card)){
			//std::cout << "Texture works: " + full_path_to_card << std::endl;
			Card the_card(full_path_to_card,card_size,current_coordinates);
			my_cards.push_back(the_card);
			addStepOnCoordinates(&current_coordinates,&card_size,cards_offset);
		}
		current_deck++;

	}
	return true;

}
void Carddeck::addStepOnCoordinates(sf::Vector2f* pos, sf::Vector2f* cardsize, float offset){
	pos->x = pos->x  + cardsize->x+ offset;
}

void Carddeck::addCard(Card new_card){
	my_cards.push_back(new_card);
}

Card Carddeck::drawCard(){
	/**
	 *
	 * lahko vrnemo le referenco do karte... ne moremo kar vrniti karto in jo izbrisati iz my_cards ker potem
	 * izgubimo podatek ki ga referencira izbrisani podatek....
	 */
	//return my_cards.back();
	Card last_card = my_cards.back();
	my_cards.pop_back();
	return last_card;
}


